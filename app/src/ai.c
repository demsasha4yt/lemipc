/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:16:49 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/20 16:25:38 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		ai_next(int *map, int *x, int *y)
{
	const int	cur_x = *x;
	const int	cur_y = *y;

	(void)map;
	srand(time(NULL));
	*x = cur_x + (rand() % 2 - 1);
	*y = cur_y + (rand() % 2 - 1);
	return (0);
}
