/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:57:51 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/21 19:40:51 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

sem_t	*open_sem(const char *sem_name)
{
	return (sem_open(sem_name, O_CREAT, 0644, 1));
}

int		unlink_sem(const char *sem_name)
{
	return (sem_unlink(sem_name));
}
