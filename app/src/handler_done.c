/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_done.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avdementev <avdementev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:17:13 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/15 15:28:30 by avdementev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		handler_done(t_player *player, t_msgbuf *buf)
{
	if (!player->isfirst)
		return (0);
	if (DEBUG)
		printf("PID %d: handler_done from %d\n", getpid(), buf->msg_text.pid);
	if (player->cur_player + 1 >= player->players_cnt)
		player->cur_player = 0;
	else 
		player->cur_player += 1;
	render(player, player->map);
	return (0);
}
