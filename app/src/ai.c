/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:16:49 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/20 18:53:36 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include "lemipc_ai.h"

void	trace_ai_next_sort(int *srtd_ply_positions, int size)
{
	int	i;
	int	x;
	int	y;

	if (!DEBUG)
		return;
	i = 0;
	printf("PID %d: trace_ai_next_sort::FROM %d(%d, %d)::", getpid(),
		mapidx(g_player.x, g_player.y), g_player.x, g_player.y);
	while (i < size)
	{
		mapxy(srtd_ply_positions[i], MAP_W, &x, &y);
		printf("%d(%d, %d); ", srtd_ply_positions[i], x, y);
		i++;
	}
	printf("\n");
}

int		ai_next(int *map, int *x, int *y)
{
	const int	cur_x = *x;
	const int	cur_y = *y;
	int			srtd_ply_positions[MAP_W * MAP_H];
	t_direction	direction;

	srand(time(NULL));
	if (ai_get_srtd_ply_positions(map, mapidx(cur_x, cur_y), MAP_W * MAP_H,
		srtd_ply_positions) < 0)
		return (-1);
	trace_ai_next_sort(srtd_ply_positions, MAP_W * MAP_H);
	direction = ai_predict_direction(srtd_ply_positions, MAP_W * MAP_H,
		cur_x, cur_y);
	if (direction.x == 0 && direction.y == 0)
		return (-1);
	*x = cur_x + direction.x;
	*y = cur_y + direction.y;
	return (0);
}
