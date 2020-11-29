/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:07:23 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/28 18:30:20 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static int	tick(t_player *player, int *map)
{
	(void)player;
	(void)map;
	if (islocked(player->sem_id))
		return (0);
	printf("pid %d: tick.\n", getpid());
	lock(player->sem_id);
	unlock(player->sem_id);
	return (0);
}

int			mainloop(t_player *player, int *map)
{
	while (!tick(player, map))
		usleep(100000);
	if (player->isfirst)
	{
		if (shmctl(g_player.shm_id, IPC_RMID, NULL) == -1)
			perror("shmctl");
		if (msgctl(g_player.msg_id, IPC_RMID, NULL) == -1)
			perror("msgctl");
		if (semctl(g_player.sem_id, 1, IPC_RMID) == -1)
			perror("semctl");
	}
	return (0);
}
