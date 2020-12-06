/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:13:25 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 16:32:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	proto_init_handlers(t_player *player)
{
	player->handlers[0] = NULL;
	player->handlers[PROTO_ENTER] = &handler_enter;
	player->handlers[PROTO_REQ] = &handler_req;
	player->handlers[PROTO_YES] = &handler_yes;
	player->handlers[PROTO_NO] = &handler_no;
	player->handlers[PROTO_KICK] = &handler_kick;
	player->handlers[PROTO_DONE] = &handler_done;
	player->handlers[PROTO_EXIT] = &handler_exit;
}

int		proto_handle(t_player *player, int proto, t_msgbuf *msg)
{
	if (DEBUG)
		printf("PID %d: proto_handle (%d)\n", getpid(), proto);
	if (msg == NULL || player == NULL) {
		dprintf(2, "player and msg required\n");
		return (-1);
	}
	if (proto < 0 || proto > HANDLERS_CNT)
	{
		dprintf(2, "PID %d: proto number %d does not exist\n", getpid(), proto);
		return (-1);
	}
	if (player->handlers[proto] == NULL)
	{
		dprintf(2, "PID %d: proto number %d does not exists\n", getpid(), proto);
		return (-1);
	}
	return (player->handlers[proto](player, msg));
}
