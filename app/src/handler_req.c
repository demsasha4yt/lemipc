/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_req.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:16:54 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 18:41:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		handler_req(t_player *player, t_msgbuf *buf)
{
	int proto;

	proto = PROTO_NO;
	if (!player->isfirst)
		return (0);
	if (DEBUG)
		printf("PID %d: handler_req from %d\n", getpid(), buf->msg_text.pid);
	if (player->players[player->cur_player] == buf->msg_text.pid)
		proto = PROTO_YES;
	return (proto_send_msg(player, buf->msg_text.qid, proto, NULL));
}
