/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_msg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:00:39 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/21 20:22:02 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_MSG_H
# define LEMIPC_MSG_H

# include <sys/types.h>
# include <stdlib.h>
# include <stdint.h>

# define MAX_MSG_SIZE 200

typedef struct	s_msgbuf
{
	long		mtype;
	char		mtext[MAX_MSG_SIZE];
}				t_msgbuf;

#endif
