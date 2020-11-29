/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:57:51 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/29 18:27:56 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include "lemipc_player.h"
#include "lemipc_semun.h"

/*
**	struct sembuf p = { 0, -1, SEM_UNDO}; // semwait
**	struct sembuf v = { 0, +1, SEM_UNDO}; // semsignal
*/

int	connect_sem(t_player *player)
{
	union semun		u;
	
	player->sem_id = semget(player->key, 1, 0664);
	if (player->sem_id < 0)
		player->sem_id = semget(player->key, 1, IPC_CREAT | 0664);
	if (player->sem_id < 0)
		perror("semget");
	u.val = 1;
	if (player->sem_id < 0 || semctl(player->sem_id, 0, SETVAL, u) < 0)
		return (-1);
	return (player->sem_id);
}

struct sembuf	getsembuf(int sem_num, int op_value)
{
	struct sembuf	s;

	s.sem_num = sem_num;
	s.sem_op = op_value;
	s.sem_flg = SEM_UNDO;
	return (s);
}

int			islocked(int sem_id)
{
	(void)sem_id;
	return (0);
}

void		lock(int sem_id)
{
	struct sembuf	s;
	int				ret;

	s = getsembuf(0, -1);
	ret = semop(sem_id, &s, 1);
	if (ret < 0)
		exit(13);
}

void		unlock(int sem_id)
{
	struct sembuf	s;
	int				ret;

	s = getsembuf(0, +1);
	ret = semop(sem_id, &s, 1);
	if (ret < 0)
		exit(13);
}
