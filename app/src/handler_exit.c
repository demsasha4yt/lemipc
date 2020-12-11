/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:17:25 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 16:19:26 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static int	handle_exit(t_player *player, int pid, t_msgbuf *buf)
{
	int		i;

	i = 0;
	while (i < player->players_cnt)
	{
		if (player->players[i] == pid)
		{
			while (i + 1 < player->players_cnt)
				player->players[i] = player->players[i + 1];
			player->players_cnt--;
			handler_done(player, buf);
			return (0);
		}
		i++;
	}
	return (0);
}

int		handler_exit(t_player *player, t_msgbuf *buf)
{
	int	exit_pid;

	if (!player->isfirst)
		return (0);
	exit_pid = buf->msg_text.pid;
	if (exit_pid < 0)
		return (0);
	return (handle_exit(player, exit_pid, buf));
}
