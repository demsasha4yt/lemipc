/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:14:14 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/20 18:34:25 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/types.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <sys/ipc.h>
# include <sys/msg.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <signal.h>

# include "lemipc_player.h"
# include "lemipc_msg.h"
# include "lemipc_proto.h"

# define DEBUG					1
# define PRINT_MAP				1

# define HOST_KEY_PATHNAME		"/tmp/lemipc_server_key"
# define MAP_SIZE				30
# define MAP_W					5
# define MAP_H					10

# define WAIT_U_TIME_DEFAULT	1000000
# define WAIT_U_TIME			WAIT_U_TIME_DEFAULT

t_player	g_player;

/*
** connect_shm creates or connect to map of `map_size` in SHM by `shm_name`
*/
int			connect_shm(t_player *player, void **data, int size);
/*
** unlink_shm unlinks from shm or destroy it by `shm_name`
*/
int			unlink_shm(const char *shm_name);

/*
** mmap_data returns shared memory of size from fd
*/
void		*mmap_data(size_t size, int fd);

/*
** unmap data for this ptr 
*/
void		munmap_data(void *ptr, size_t size);

/*
** open_sem creates or connect to semaphore by `sem_name`
*/
sem_t		*open_sem(const char *sem_name);

/*
** unlink_sem unlinks semaphore by its `sem_name`
*/
int			unlink_sem(const char *sem_name);

/*
** connect_sem creates or connect semaphore
*/
int			connect_sem(t_player *player);

/*
** lock locks shm by semaphore
*/
void		lock(int sem_id);

/*
** unlock unlocks shm by semaphore
*/
void		unlock(int sem_id);

/*
** connect_msgq tries to create or connect to msgq.
*/
int			connect_msgq(t_player *player);

/*
** destroy_msgq destroys /tmp/lemipc_msgq file
*/
void		destroy_msgq();

/*
** get_msgq_qid ...
*/
int			get_msgq_qid(key_t key);

/*
** send_msgqto sends message to dest msg_id
** in case of error returns -1, otherwise - 0
*/
int			send_msgqto(int dest, t_msgbuf *message);

/*
** recv_msgq recieves msg to player->msg_id and writes it to dest
** in case of error returns -1, otherwise - 0
*/
int			recv_msgq(t_player *player, t_msgbuf *dest);

/*
** [APP LOGIC] ******************
*/

/*
** mainloop starts the application
*/
int			mainloop(t_player *player, int *map);

/*
** placeonmap puts player on map in random empty place
** returns -1 in case there is no place or error
** returns 0 on success
*/
int			placeonmap(t_player *player, int **map);

/*
** mapidx returns an array index in map by x,y coords.
*/
int			mapidx(int x, int y);

/*
** mapxy gets x, y coords by array index
*/
int			mapxy(int idx, int map_w, int *x, int *y);

/*
** diffidxs count steps from idx to idx2
*/
int			diffidxs(int map_w, int idx, int idx2);

/*
** changepos changes player pos on map and writes it to player->x, player->y
** returns -1 of there is an error, otherwise 0
*/
int			changepos(t_player *player, int **map, int new_x, int new_y);

/*
** handle_step handles main logic of the step for each player
** returns -1 in case of error or player must exit from the game
** return 0 on success
*/
int			handle_step(t_player *player, int *map);

/*
** render prints map to the screen
*/
void		render(t_player *player, int *map);

/*
** clear clears all data and destroys sem, shm, msgq on sigint
*/
void		clear(t_player *player);

/*
** clearone destroys msgq when player is killed
** execute clear(player) in case of player is first
*/
void		clearone(t_player *player);

/*
** ai_next calculates new position for player and place it to *x and *y
** pass &player->x and &player->y inside
** returns 0 on success, -1 on error
*/
int			ai_next(int *map, int *x, int *y);

/*
** [PROTO] **********************
*/

/*
** proto_init_handlers ...
*/
void		proto_init_handlers(t_player *player);

/*
** msg_request_enter sends mgs to host with request to enter the game
** in case of error returns -1, otherwise - 0
*/
int			proto_request_enter(t_player *player);

/*
** proto_request_step ...
*/
int			proto_request_step(t_player *player);

/*
** proto_recv_msg ...
*/
int			proto_recv_msg(t_player *player);

/*
** proto_send_msg ...
*/
int			proto_send_msg(t_player *player, int dest, int proto, t_payload *payload);

/*
** proto_kick kicks player from game...
*/
int			proto_kick(t_player *player, int kicked_pid);

/*
** proto_handle ...
*/
int			proto_handle(t_player *player, int proto, t_msgbuf *msg);

/*
** [HANDLERS] ******************
*/

/*
** handler_done ...
*/
int		handler_done(t_player *player, t_msgbuf *buf);

/*
** handler_enter ...
*/
int		handler_enter(t_player *player, t_msgbuf *buf);

/*
** handler_exit ...
*/
int		handler_exit(t_player *player, t_msgbuf *buf);

/*
** handler_kick ...
*/
int		handler_kick(t_player *player, t_msgbuf *buf);

/*
** handler_no ...
*/
int		handler_no(t_player *player, t_msgbuf *buf);

/*
** handler_req ...
*/
int		handler_req(t_player *player, t_msgbuf *buf);

/*
** handler_yes ...
*/
int		handler_yes(t_player *player, t_msgbuf *buf);

#endif
