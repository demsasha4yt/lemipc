/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avdementev <avdementev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:03:18 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/15 15:29:33 by avdementev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include "lemipc_player.h"
#include <string.h>

static int	usage(void)
{
	printf("Usage: ./lemipc (number of the team)\n");
	return (EXIT_FAILURE);
}

static void	gen_ftok_path(t_player *player)
{
	char touch_str[PLAYER_FTOK_LEN + 6];

	snprintf(player->player_key_host, PLAYER_FTOK_LEN, "/tmp/%d", getpid());
	snprintf(touch_str, PLAYER_FTOK_LEN + 6, "touch /tmp/%d", getpid());
	system("touch /tmp/lemipc_server_key");
	system(touch_str);
}

static int	lemipc_init(char **argv, t_player *player, int **map)
{
	gen_ftok_path(player);
	player->key = ftok(HOST_KEY_PATHNAME, 0);
	player->alive = 0;
	player->players = NULL;
	player->isfirst = 0;
	player->state = STATE_NOENTER;
	player->cur_player = 0;
	player->players_cnt = 0;
	if (argv[1][0] < '0' || argv[1][0] > '9')
		return (usage());
	if ((player->team_nb = atoi(argv[1])) < 1)
		return (-1);
	connect_shm(player, (void**)map, MAP_W * MAP_H * sizeof(int));
	connect_sem(player);
	player->msg_key = (player->isfirst) ? player->key :
		ftok(player->player_key_host, 0);
	connect_msgq(player);
	if ((*map = shmat(player->shm_id, NULL, 0)) == (void *)-1)
		return (1);
	proto_init_handlers(player);
	if (player->isfirst)
		player->players = (int*)malloc(sizeof(int) * MAP_W * MAP_H);
	return (0);
}

void		sigint(int sig)
{
	clear(&g_player);
	exit(sig);
}

int			main(int argc, char **argv)
{
	int			*map;

	if (argc != 2)
		exit(usage());
	srand(time(NULL));
	if (lemipc_init(argv, &g_player, &map))
		exit(EXIT_FAILURE);
	signal(SIGINT, sigint);
	signal(SIGKILL, sigint);
	signal(SIGTERM, sigint);
	g_player.map = map;
	mainloop(&g_player, map);
	return (EXIT_SUCCESS);
}
