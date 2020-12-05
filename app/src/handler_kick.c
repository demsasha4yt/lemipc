/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_kick.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:16:05 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 19:19:06 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		handler_kick(t_player *player, t_msgbuf *buf)
{
	if (!player->onmap)
		return (-1);
	player->state = STATE_KICKED;
	(void)buf;
	return (0);
}
