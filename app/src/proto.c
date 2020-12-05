/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:41:28 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 16:30:06 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		proto_request_enter(t_player *player)
{
	if (player->state != STATE_NOENTER)
		return (0);
	if (proto_send_msg(player, player->msgh_id, PROTO_ENTER, NULL) < 0)
		return (-1);
	player->state = STATE_REQENTER;
	return (0);
}

int			proto_send_msg(t_player *player, int dest, int proto, t_payload *payload)
{
	t_msgbuf	message;

	message = get_msgbuf();
	message.mtype = 1;
	message.msg_text.pid = getpid();
	message.msg_text.qid = player->msg_id;
	message.msg_text.proto = proto;
	if (payload)
	{
		message.msg_text.payload.x = payload->x;
		message.msg_text.payload.y = payload->y;
	}
	if (DEBUG)
		printf("PID %d: send [PROTO %d] to %d, payload=%p\n",
			getpid(), proto, dest, payload);
	if (send_msgqto(dest, &message) < 0)
		return (-1);
	return (0);
}

int			proto_recv_msg(t_player *player)
{
	int			ret;
	t_msgbuf	msg;

	if (player->state == STATE_NOENTER)
		return (0);
	ret = recv_msgq(player, &msg);
	if (ret < 0)
		return (-1);
	if (msg.msg_text.pid < 0 || msg.msg_text.qid < 0 || msg.msg_text.proto < 0)
	{
		if (DEBUG)
			printf("msg rcvd and skipped becouse [%d %d %d]",
				msg.msg_text.pid, msg.msg_text.qid, msg.msg_text.proto);
		return (0);
	}
	if (DEBUG)
		printf("PID %d: rcvd [PROTO %d] from %d, payload=(%d,%d)\n",
			getpid(), msg.msg_text.proto, msg.msg_text.qid,
				msg.msg_text.payload.x, msg.msg_text.payload.y);
	return (proto_handle(player, msg.msg_text.proto, &msg));
}
