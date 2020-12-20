/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:55:46 by avdementev        #+#    #+#             */
/*   Updated: 2020/12/20 16:28:21 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static int					state_kicked(t_player *player, int *map)
{
	if (!player->onmap)
		return (-1);
	(void)map;
	// TODO: handle clear player on map
	return (-1);
}

static int					state_noenter(t_player *player, int *map)
{
	if (player->onmap)
		return (-1);
	if (placeonmap(player, &map))
		return (-1);
	if (DEBUG)
		printf("PID %d: placed on map in (%d, %d)", getpid(), player->x, player->y);
	player->onmap = 1;
	player->state = STATE_WAIT;
	return (0);
}

int		handle_step(t_player *player, int *map)
{
	int		x;
	int		y;

	if (player->state == STATE_KICKED)
		return (state_kicked(player, map));
	if (!player->onmap)
		return (state_noenter(player, map));
	x = player->x;
	y = player->y;
	if (ai_next(map, &x, &y) < 0)
		return (-1);
	if (changepos(player, &map, x, y) < 0)
		return (-1);
	printf("pid %d: tick. is_first = %d, msgid = %d, msghid = %d,\
	state = %d\n", getpid(), player->isfirst, player->msg_id, player->msgh_id,
	player->state);
	fflush(0);
	player->state = STATE_WAIT;
	return (0);
}
