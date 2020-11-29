/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:07:23 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/29 19:37:08 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static int	tick(t_player *player, int *map)
{
	lock(player->sem_id);
	printf("pid %d: tick. is_first = %d, msgid = %d, msghid = %d\n", getpid(),
		player->isfirst, player->msg_id, player->msgh_id);
	fflush(0);
	usleep(WAIT_U_TIME);
	unlock(player->sem_id);
	(void)map;
	return (0);
}

int			mainloop(t_player *player, int *map)
{
	while (!tick(player, map))
		usleep(WAIT_U_TIME);
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
