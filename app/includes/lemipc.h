/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:14:14 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/21 19:48:52 by bharrold         ###   ########.fr       */
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

# define SHM_NAME "/lemipc_shm"
# define SEM_NAME "/lemipc_sem"
# define MAP_SIZE 100

/*
** connect_shm creates or connect to map of `map_size` in SHM by `shm_name`
*/
int			connect_shm(const char *shm_name, int64_t map_size);

/*
** unlink_shm unlinks from shm or destroy it by `shm_name`
*/
int			unlink_shm(const char *shm_name);

/*
** open_sem creates or connect to semaphore by `sem_name`
*/
sem_t		*open_sem(const char *sem_name);

/*
** unlink_sem unlinks semaphore by its `sem_name`
*/
int			unlink_sem(const char *sem_name);

/*
** connect_msgq tries to create /tmp/lemipc_msgq file and returns ftok of this file
*/
key_t		connect_msgq();

/*
** destroy_msgq destroys /tmp/lemipc_msgq file
*/
void		destroy_msgq();

/*
** get_msgq_qid ...
*/
int			get_msgq_qid(key_t key);

#endif
