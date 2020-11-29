/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:07:51 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/29 19:33:41 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_PLAYER_H
# define LEMIPC_PLAYER_H

# include <sys/sem.h>

# define PLAYER_FTOK_LEN 20

/*
** t_player struct
*/
typedef struct	s_player
{
	char		player_key_host[PLAYER_FTOK_LEN];
	key_t		key;
	key_t		msg_key;
	int			shm_id;
	int			sem_id;
	int			msg_id;
	int			msgh_id;
	int			isfirst;
	int			alive;
	int			active;
	int			x;
	int			y;
	int			team_nb;
}				t_player;

#endif
