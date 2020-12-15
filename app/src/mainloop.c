/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avdementev <avdementev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:07:23 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/15 15:23:06 by avdementev       ###   ########.fr       */
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

static int					step(t_player *player, int *map)
{
	int			step_ret;
	t_payload	payload;

	if (player->state != STATE_STEP && player->state != STATE_KICKED)
		return (0);
	lock(player->sem_id);
	step_ret = handle_step(player, map);
	if (step_ret == 0)
		proto_send_msg(player, player->msgh_id, PROTO_DONE, NULL);
	payload.x = player->x;
	payload.y = player->y;
	if (step_ret < 0)
		proto_send_msg(player, player->msgh_id, PROTO_EXIT, &payload);
	usleep(getsleeptime(player));
	unlock(player->sem_id);
	return (step_ret);
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
