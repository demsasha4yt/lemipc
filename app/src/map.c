/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:07:46 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 19:31:40 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		placeonmap(t_player *player, int **map)
{
	(void)player;
	(void)map;
	return (0);
}

void	render(t_player *player)
{
	(void)player;
	if (DEBUG)
		printf("PID %d: render map", getpid());
	if (PRINT_MAP)
	{
		// TODO: Print map (or render with graphic mode);
	}
}
