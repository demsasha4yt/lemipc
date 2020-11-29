/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:03:18 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/28 18:37:33 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include "lemipc_player.h"
#include <string.h>

/*
** usage prints usage to the screen and returns EXIT_FAILURE CODE
*/
static int usage()
{
	printf("Usage: ./lemipc (number of the team)\n");
	return (EXIT_FAILURE);
}

/*
** lemipc_init inits game
*/
static int	lemipc_init(int argc, char **argv, t_player *player, int **map)
{
	player->key = ftok(argv[1], 0);
	player->alive = 0;
	if (argv[1][0] < '0' || argv[1][0] > '9')
		return (usage());
	player->team_nb = atoi(argv[1]);
	player->isfirst = 0;
	connect_shm(player, (void**)map, MAP_W * MAP_H * sizeof(int));
	connect_sem(player);
	connect_msgq(player);
	semctl(player->sem_id, 0, SETVAL, 1);
	if ((*map = shmat(player->shm_id, NULL, 0)) == (void *)-1)
		return (1);
	printf("%d\n%d\n%d\n%d\n", player->shm_id, player->sem_id, player->msg_id, player->isfirst);
	(void)argc;
	return (0);
}

void	sigint(int sig)
{
	printf("sigint\n");
	printf("destroy %d\n", g_player.shm_id);
	if (shmctl(g_player.shm_id, IPC_RMID, NULL) == -1)
		perror("shmctl");
	if (msgctl(g_player.msg_id, IPC_RMID, NULL) == -1)
		perror("msgctl");
	if (semctl(g_player.sem_id, 1, IPC_RMID) == -1)
		perror("semctl");
	exit(SIGINT);
	(void)sig;
}

int main (int argc, char **argv)
{
	int			*map;

	if (argc != 2)
		exit(usage());
	srand(time(NULL));
	if(lemipc_init(argc, argv, &g_player, &map))
		exit(EXIT_FAILURE);
	signal(SIGINT, sigint);
	mainloop(&g_player, map);
	return (EXIT_SUCCESS);
}
