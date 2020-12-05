/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_yes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:15:18 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 18:08:15 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static int	handler_placeonmap(t_player *player)
{
	if (DEBUG)
		printf("PID %d: handler_yes(placeonmap)\n", getpid());
	player->onmap = 0;
	player->state = STATE_WAIT;
	return (0);
}

static int	handler_step(t_player *player)
{
	if (DEBUG)
		printf("PID %d: handler_yes(step)\n", getpid());
	player->state = STATE_STEP;
	return (0);
}

int		handler_yes(t_player *player, t_msgbuf *buf)
{
	if (player->state == STATE_REQENTER)
		return (handler_placeonmap(player));
	if (player->state == STATE_RESPWAIT)
		return (handler_step(player));
	(void)buf;
	return (0);
}
