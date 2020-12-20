/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:48:04 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/20 18:56:12 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lemipc.h"
#include "lemipc_ai.h"

int		compare_diffs(const void *a, const void *b)
{
	t_diffs	*arg1;
	t_diffs	*arg2;

	arg1 = (t_diffs*)a;
	arg2 = (t_diffs*)b;
	if (arg1->distance < arg2->distance)
		return (-1);
	if (arg1->distance > arg2->distance)
		return (1);
	return (0);
}

static int	conv_to_result(int *dest, t_diffs *difs, int size)
{
	int		i;

	i = 0;
	if (DEBUG)
		printf("PID %d: ai_read::conv_to_result\n", getpid());
	while (i < size)
	{
		dest[i] = difs[i].idx;
		i++;
	}
	return (0);
}

int		ai_get_srtd_ply_positions(int *map, int ply_idx, int map_size, int *result)
{
	int		i;
	t_diffs	diffs[map_size];

	if (DEBUG)
		printf("PID %d: ai_get_srtd_ply_positions\n", getpid());
	i = 0;
	while (i < map_size)
	{
		diffs[i].idx = i;
		if (map[i] == 0 || i == ply_idx)
		{
			diffs[i].distance = INT32_MAX;
			i++;
			continue;
		}
		diffs[i].distance = diffidxs(MAP_W, ply_idx, i);
		i++;
	}
	qsort(diffs, map_size, sizeof(t_diffs), compare_diffs);
	return (conv_to_result(result, diffs, map_size));
}
