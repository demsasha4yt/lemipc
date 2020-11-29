/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:47:58 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/29 14:31:54 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include "lemipc_player.h"

int		connect_shm(t_player *player, void **data, int size)
{
	
	if ((player->shm_id = shmget(player->key, size, SHM_W | SHM_R | IPC_EXCL)) == -1)
	{
		player->shm_id = shmget(player->key, size, IPC_CREAT | 0664);
		if (player->shm_id < 0)
		{
			perror("shmget");
			return(player->shm_id);
		}
		player->isfirst = 1;
		*data = shmat(player->shm_id, NULL, 0);
		memset(*data, 0, size);
	}
	return (player->shm_id);
}
