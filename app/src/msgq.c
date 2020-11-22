/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgq.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:46:26 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/21 23:25:21 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

key_t	connect_msgq()
{
	key_t	key;

	system("touch /tmp/lemipc_msgq");
	key = ftok("/tmp/lemipc_msgq", 42);
	return (key);
}

void	destroy_msgq()
{
	system("rm /tmp/lemipc_msgq");
}

int		get_msgq_qid(key_t key)
{
	int qid;

	qid = msgget(key, 0666 | IPC_PRIVATE);
	if (qid < 0)
		perror("msgget");
	if (qid == 0)
	{
		printf(" Got msgid == 0!!, errono = %s\n", strerror(errno));
	}
	return (qid);
}
