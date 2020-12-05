/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgq.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:46:26 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 15:50:42 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include "lemipc_msg.h"

int			connect_msgq(t_player *player)
{
	player->msg_id = msgget(player->msg_key, 0664);
	if (player->msg_id < 0)
		player->msg_id = msgget(player->msg_key, IPC_CREAT | 0664);
	if (player->msg_id < 0)
		perror("msgget");
	player->msgh_id = msgget(player->key, 0664);
	return (player->msg_id);
}

int			recv_msgq(t_player *player, t_msgbuf *dest)
{
	if (DEBUG)
		printf("recv_msgq\n");
	if (msgrcv(player->msg_id, dest, sizeof (t_msgbuf), 0, 0) == -1)
	{
		perror("msgrcv");
		return (-1);
	}
	return (0);
}

int			send_msgqto(int dest, t_msgbuf *message)
{
	if (msgsnd(dest, message, sizeof(t_msgbuf), 0) == -1)
	{
		perror("msgsnd to");
		return (-1);
	}
	return (0);
}

t_msgbuf	get_msgbuf()
{
	t_msgbuf	msg;

	msg.mtype = 1;
	msg.msg_text.payload.x = -1;
	msg.msg_text.payload.y = -1;
	msg.msg_text.pid = -1;
	msg.msg_text.qid = -1;
	msg.msg_text.proto = -1;
	return (msg);
}
