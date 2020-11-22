/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgq.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:46:26 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/22 20:00:25 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		connect_msgq(t_player *player)
{
	player->msg_id = msgget(player->key, 0664);
	if (player->msg_id < 0)
		player->msg_id = msgget(player->key, IPC_CREAT | 0664);
	if (player->msg_id < 0)
		perror("msgget");
	return (player->msg_id);
}
