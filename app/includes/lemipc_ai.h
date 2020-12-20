/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_ai.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:27:58 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/20 18:39:35 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_AI_H
# define LEMIPC_AI_H

typedef struct	s_diffs
{
	int			idx;
	int			distance;
}				t_diffs;

typedef struct	s_direction
{
	int			x;
	int			y;
}				t_direction;

/*
** ai_get_srtd_ply_positions returns positions of players sorted
** by distance between
** returns 0 on success, -1 on error
*/
int				ai_get_srtd_ply_positions(int *map, int ply_idx, int map_size,
	int *result);

/*
**	ai_predict_direction returns directions for next position;
*/
t_direction		ai_predict_direction(int *srtd_ply_positions, int map_size, 
	int cur_x, int cur_y);

#endif
