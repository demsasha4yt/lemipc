/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:57:51 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/22 20:32:35 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include "lemipc_player.h"

int	connect_sem(t_player *player)
{
	player->sem_id = semget(player->key, 1, 0664);
	if (player->sem_id < 0)
		player->sem_id = semget(player->key, 1, IPC_CREAT | 0664);
	if (player->sem_id < 0)
		perror("semget");
	return (player->sem_id);
}

struct sembuf	getsem_op(int sem_num, int op_value)
{
	struct sembuf sops;

	sops.sem_num = sem_num;
	sops.sem_op = op_value;
	sops.sem_flg = 0;
	return (sops);
}

int			islocked(int sem_id)
{
	int	value;
	sem_getvalue(sem_id, &value);
	return (value);
}

void		lock(int sem_id)
{
	struct sembuf sops;

	sops = getsem_op(0, -1);
	semop(sem_id, &sops, 1);
}

void		unlock(int sem_id)
{
	struct sembuf sops;

	sops = getsem_op(0, 1);
	semop(sem_id, &sops, 1);
}
