/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:47:58 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/21 18:22:46 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		connect_shm(const char *shm_name, int64_t map_size)
{
	int		fd;
	
	fd = shm_open(shm_name, O_RDWR | O_CREAT | O_EXCL, 0644);
	if (fd < 0 && errno == EEXIST)
		fd = shm_open(shm_name, O_RDWR | O_EXCL, 0644);
	if ((ftruncate(fd, map_size * map_size)) < 0) {
		return (EXIT_FAILURE);
	}
	return (fd);
}

int		unlink_shm(const char *shm_name)
{
	return (shm_unlink(shm_name));
}
