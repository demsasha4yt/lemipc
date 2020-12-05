/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:07:51 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 19:34:49 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_PLAYER_H
# define LEMIPC_PLAYER_H

# include <sys/sem.h>

# include "lemipc_msg.h"
# include "lemipc_proto.h"

# define PLAYER_FTOK_LEN	20

# define STATE_NOENTER		1
# define STATE_REQENTER		2
# define STATE_WAIT			3
# define STATE_RESPWAIT		4
# define STATE_STEP			5
# define STATE_KICKED		6
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
	int			state;
	int			alive;
	int			onmap;
	int			x;
	int			y;
	int			team_nb;
	int			(*handlers[HANDLERS_CNT + 1])(struct s_player *p, t_msgbuf *b);
	int			*players;
	int			players_cnt;
	int			cur_player;
}				t_player;

#endif
