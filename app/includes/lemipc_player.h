/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:07:51 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/22 17:58:35 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_PLAYER_H
# define LEMIPC_PLAYER_H

#include <sys/sem.h>

/*
** t_player struct
*/
typedef struct	s_player
{
	key_t		key;
	int			shm_id;
	int			sem_id;
	int			msg_id;
	int			isfirst;
	int			alive;
	int			active;
	int			x;
	int			y;
	int			team_nb;
}				t_player;

#endif
