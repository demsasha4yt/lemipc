/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:07:23 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 19:03:01 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static inline useconds_t	getsleeptime(t_player *player)
{
	int	cnt;

	if (player->isfirst)
	{
		cnt = player->players_cnt;
		if (!cnt)
			cnt = 1;
		return (WAIT_U_TIME / cnt);
	}
	return (WAIT_U_TIME);
}

static int					step(t_player *player, int *map)
{
	if (player->state != STATE_STEP)
		return (0);
	lock(player->sem_id);
	printf("pid %d: tick. is_first = %d, msgid = %d, msghid = %d\n", getpid(),
		player->isfirst, player->msg_id, player->msgh_id);
	fflush(0);
	(void)map;
	player->state = STATE_WAIT;
	proto_send_msg(player, player->msgh_id, PROTO_DONE, NULL);
	usleep(getsleeptime(player));
	unlock(player->sem_id);
	return (0);
}

static int					tick(t_player *player, int *map)
{
	if (proto_request_enter(player) < 0)
		return (-1);
	if (proto_request_step(player) < 0)
		return (-1);
	if (proto_recv_msg(player) < 0)
		return (-1);
	step(player, map);
	return (0);
}

int							mainloop(t_player *player, int *map)
{
	while (!tick(player, map))
		usleep(getsleeptime(player));
	clearone(player);
	return (0);
}
