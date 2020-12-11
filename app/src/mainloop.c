/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:07:23 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 19:34:27 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static inline useconds_t	getsleeptime(t_player *player)
{
	int	cnt;

	if (player->isfirst)
	{
		cnt = player->players_cnt;
		if (cnt <= 0)
			cnt = 1;
		return (WAIT_U_TIME / cnt);
	}
	return (WAIT_U_TIME);
}

static int					state_kicked(t_player *player, int *map)
{
	(void)player;
	(void)map;
	// TODO: handle clear player on map
	return (-1);
}


static int					step(t_player *player, int *map)
{
	if (player->state != STATE_STEP && player->state != STATE_KICKED)
		return (0);
	lock(player->sem_id);
	if (player->state == STATE_KICKED)
		return (state_kicked(player, map));
	printf("pid %d: tick. is_first = %d, msgid = %d, msghid = %d,\
	state = %d\n", getpid(), player->isfirst, player->msg_id, player->msgh_id,
	player->state);
	fflush(0);
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
	return (step(player, map));
}

int							mainloop(t_player *player, int *map)
{
	while (!tick(player, map))
		usleep(getsleeptime(player));
	clearone(player);
	return (0);
}
