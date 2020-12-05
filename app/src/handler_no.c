/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_no.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:15:53 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 18:29:54 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		handler_no(t_player *player, t_msgbuf *buf)
{
	if (player->state != STATE_RESPWAIT)
		return (0);
	if (DEBUG)
		printf("PID %d: handler_no\n", getpid());
	player->state = STATE_WAIT;
	(void)buf;
	return (0);
}
