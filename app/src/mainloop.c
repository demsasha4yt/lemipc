/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:07:23 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 15:11:51 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static inline useconds_t	getsleeptime(t_player *player)
{
	if (player->isfirst)
		return (WAIT_U_TIME_HOST);
	else
		return (WAIT_U_TIME);
}

static int					step(t_player *player, int *map)
{
	if (player->state != STATE_STEP)
		return (0);
	lock(player->sem_id);
	if (DEBUG)
		printf("pid %d: tick. is_first = %d, msgid = %d, msghid = %d\n", getpid(),
			player->isfirst, player->msg_id, player->msgh_id);
	fflush(0);
	(void)map;
	usleep(getsleeptime(player));
	unlock(player->sem_id);
	return (0);
}

static int					tick(t_player *player, int *map)
{
	proto_recv_msg(player);
	proto_request_enter(player);
	step(player, map);
	return (0);
}

int							mainloop(t_player *player, int *map)
{
	while (!tick(player, map))
		usleep(getsleeptime(player));
	if (player->isfirst)
	{
		if (shmctl(g_player.shm_id, IPC_RMID, NULL) == -1)
			perror("shmctl");
		if (semctl(g_player.sem_id, 1, IPC_RMID) == -1)
			perror("semctl");
	}
	if (msgctl(g_player.msg_id, IPC_RMID, NULL) == -1)
			perror("msgctl");
	return (0);
}
