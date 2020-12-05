/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:50:25 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 18:54:12 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	clear(t_player *player)
{
if (shmctl(player->shm_id, IPC_RMID, NULL) == -1)
		perror("shmctl");
	if (!player->isfirst)
	{
		if (msgctl(player->msg_id, IPC_RMID, NULL) == -1)
			perror("msgctl");
	}
	if (msgctl(player->msgh_id, IPC_RMID, NULL) == -1)
		perror("msgctl");
	if (semctl(player->sem_id, 1, IPC_RMID) == -1)
		perror("semctl");
	if (player->isfirst && player->players != NULL)
		free(player->players);
	write(0, "\n", 1);
	fflush(0);
}

void	clearone(t_player *player)
{
	if (player->isfirst)
	{
		clear(player);
		return ;
	}
	if (msgctl(g_player.msg_id, IPC_RMID, NULL) == -1)
			perror("msgctl");
}
