/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgq.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:46:26 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/29 19:37:19 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include "lemipc_msg.h"

int		connect_msgq(t_player *player)
{
	player->msg_id = msgget(player->msg_key, 0664);
	if (player->msg_id < 0)
		player->msg_id = msgget(player->msg_key, IPC_CREAT | 0664);
	if (player->msg_id < 0)
		perror("msgget");
	player->msgh_id = msgget(player->key, 0664);
	return (player->msg_id);
}

int		recv_msgq(t_player *player, t_msgbuf *dest)
{
	if (msgrcv(player->msg_id, &dest, sizeof (t_msgbuf), 0, 0) == -1)
	{
		perror("msgrcv");
		return (-1);
	}
	return (0);

}

int		send_msgq(t_player *player, t_msgbuf *message)
{
	if (msgsnd(player->msg_id, message, sizeof(t_msgbuf), 0) == -1)
	{
		perror("msgsnd send");
		return (-1);
	}
	return (0);
}

