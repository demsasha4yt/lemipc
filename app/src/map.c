/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avdementev <avdementev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:07:46 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/15 17:59:04 by avdementev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static int get_free_spaces(int **map, const int map_size, int *free, int *free_count)
{
	int		i;

	*free_count = 0;
	i = 0;
	while (i < map_size)
	{
		if ((*map)[i] == 0)
		{
			free[*free_count] = i;
			*free_count += 1;
		}
		i++;
	}
	return (0);
}

int		placeonmap(t_player *player, int **map)
{
	const int			map_size = MAP_W * MAP_H;
	int					free[map_size];
	int					count;
	int					random;

	memset(free, -1, map_size);
	count = 0;
	if (get_free_spaces(map, map_size, free, &count) < 0)
		return (-1);
	if (count <= 0 || free[0] == -1)
		return (-1);
	random = rand() % count;
	if (random < 0 || free[random] < 0)
		return (-1);
	(*map)[free[random]] = player->team_nb;
	player->x = free[random] % MAP_W;
	player->y = free[random] / MAP_W;
	return (0);
}

int		changepos(t_player *player, int **map, int new_x, int new_y)
{
	const int	old_idx = mapidx(player->x, player->y);
	const int	new_idx = mapidx(new_x, new_y);

	if ((*map)[new_idx] != 0 || (*map)[old_idx] == 0)
		return (-1);
	return (0);
}

void	render(t_player *player, int *map)
{
	const int	size = MAP_W * MAP_H;
	int			i;

	if (!player->isfirst)
		return ;
	if (DEBUG)
		printf("PID %d: render map\n", getpid());
	if (!PRINT_MAP)
		return ;
	i = 0;
	while (i < size)
	{
		if (i != 0 && i % MAP_W == 0)
			printf("\n");
		printf("%d ", map[i]);
		i++;
	}
	printf("\n");
}
