/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_prediction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:30:23 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/20 18:54:28 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include "lemipc_ai.h"

static int			check(int dest_idx, int cur_idx, int map_size)
{
	if (dest_idx < 0 || dest_idx >= map_size || cur_idx < 0 ||
		cur_idx >= map_size)
		return (0);
	return (1);
}

static t_direction	conv_to_direction(int dest_idx, int cur_idx, int map_size)
{
	t_direction	direction;

	direction.x = 0;
	direction.y = 0;
	if (dest_idx >= 0 && dest_idx < map_size && cur_idx >= 0 &&
		cur_idx < map_size)
	{
	}
	return (direction);
}

t_direction			ai_predict_direction(int *srtd_ply_positions, int map_size,
	int cur_x, int cur_y)
{
	const int	cur_idx = mapidx(cur_x, cur_y);
	int			i;
	int			dest_idx;

	dest_idx = -1;
	if (DEBUG)
		printf("PID %d: ai_prediction::ai_predict_direction\n", getpid());
	i = 0;
	while (i < map_size)
	{
		if (check(srtd_ply_positions[i], cur_idx, map_size))
		{
			dest_idx = i;
			break;
		}
	}
	return (conv_to_direction(dest_idx, cur_idx, map_size));
}
