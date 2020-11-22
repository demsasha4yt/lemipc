/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:03:18 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/21 23:28:01 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include "lemipc_msg.h"

/*
** lemipc_init inits game
*/
static void	lemipc_init(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

int main (int argc, char **argv)
{
	int		fd;

	lemipc_init(argc, argv);
	fd = connect_shm(SHM_NAME, MAP_SIZE);
	if (fd < 0)
		exit(EXIT_FAILURE);
	if (open_sem(SEM_NAME) == SEM_FAILED)
	{
		unlink_shm(SHM_NAME);
		exit(EXIT_FAILURE);
	}
	key_t key = connect_msgq();
	int qid = get_msgq_qid(key);
	printf("PID %d: key: %d, qid: %d\n", getpid(), key, qid);
	printf ("Server: Hello, World!\n");
	t_msgbuf msg;
	t_msgbuf msgr;
	while (1)
	{
		memset(&msgr, 0, sizeof(msgr));
		sprintf(msg.mtext, "%d", getpid());
		if (argc > 1)
		{
			int qids = msgget(key, 0666 | IPC_CREAT);

			if (msgrcv(qid, &msgr, sizeof(msgr), 0, 0) == -1) {
				perror ("msgrcv");
				exit (1);
			}
			printf("pid %d, msq = %d, message rcvd from %s\n", getpid(),qids, msgr.mtext);
		} else
		{
			msg.mtype = 1;
			if (msgsnd(qid, &msg, sizeof(msg) - sizeof(long), 0) == -1) {
				perror ("msgget");
				exit (1);
			}
				printf("pid %d, message send from %s\n", getpid(), msg.mtext);
		}
		sleep(2);
	}
	unlink_sem(SEM_NAME);
	unlink_shm(SHM_NAME);
	destroy_msgq();
	return (0);
}
