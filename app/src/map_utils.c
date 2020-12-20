/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:37:51 by avdementev        #+#    #+#             */
/*   Updated: 2020/12/20 18:51:16 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		mapidx(int x, int y)
{
	return (MAP_W * y + x);
}

int		mapxy(int idx, int map_w, int *x, int *y)
{
	*x = idx % map_w;
	*y = idx / map_w;
	return (0);
}

int		diffidxs(int map_w, int idx, int idx2)
{
	int		diff;

	diff = -1;
	diff = idx % map_w - idx2 % map_w
		+ idx / map_w - idx2 / map_w;
	return (diff);
}
