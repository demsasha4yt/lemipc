/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_semun.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:30:10 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/29 14:30:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_SEMUN_H
# define LEMIPC_SEMUN_H


union				semun
{
	int				val;
	struct semid_ds	*buf;
	unsigned short	*array;
};


#endif
