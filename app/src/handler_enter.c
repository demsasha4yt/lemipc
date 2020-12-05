/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_enter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:16:32 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 18:42:07 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		handler_enter(t_player *player, t_msgbuf *buf)
{
	if (!player->isfirst) 
		return (0);
	if (DEBUG)
		printf("PID %d: handler_enter for %d\n", getpid(), buf->msg_text.pid);
	player->players[player->players_cnt] = buf->msg_text.pid;
	player->players_cnt += 1;
	return (proto_send_msg(player, buf->msg_text.qid, PROTO_YES, NULL));
}
