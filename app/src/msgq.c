/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgq.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:46:26 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/21 20:21:59 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

key_t	connect_msgq()
{
	key_t	key;

	system("touch /tmp/lemipc_msgq");
	key = ftok("/tmp/lemipc_msgq", 42);
	if (msgget(key, IPC_CREAT | 0644) < 0)
	{
		perror("msgget");
		return (-1);
	}
	msgctl(key, IPC_RMID, NULL);
	return (key);
}

void	destroy_msgq()
{
	system("rm /tmp/lemipc_msgq");
}

int		get_msgq_qid(key_t key)
{
	int qid;

	qid = msgget(key, IPC_PRIVATE | 0660);
	if (qid < 0)
		perror("msgget");
	return (qid);
}
