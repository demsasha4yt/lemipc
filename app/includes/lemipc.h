/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:14:14 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/29 18:39:29 by bharrold         ###   ########.fr       */
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

# define HOST_KEY_PATHNAME "/tmp/lemipc_server_key"
# define SHM_NAME "/tmp/lemi23234234pc"
# define SEM_NAME SHM_NAME
# define MAP_SIZE 30
# define MAP_W 30
# define MAP_H 30


# define WAIT_U_TIME_DEFAULT 100000
# define WAIT_U_TIME 1000000
t_player	g_player;

/*
** mainloop starts the application
*/
int			mainloop(t_player *player, int *map);

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
** connect_sem ...
*/
int			connect_sem(t_player *player);

/*
** lock ...
*/
void		lock(int sem_id);

/*
** unlock ...
*/
void		unlock(int sem_id);

/*
** islocked ...
*/
int			islocked(int sem_id);
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

#endif
