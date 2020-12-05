/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_msg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:00:39 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 16:00:33 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_MSG_H
# define LEMIPC_MSG_H

# include <sys/types.h>
# include <stdlib.h>
# include <stdint.h>

# define MAX_MSG_SIZE	200

typedef struct	s_payload
{
	int			x;
	int			y;
}				t_payload;

typedef struct	s_msg_text
{
	int			qid;
	pid_t		pid;
	int			proto;
	t_payload	payload;
}				t_msg_text;

typedef struct	s_msgbuf
{
	long		mtype;
	t_msg_text	msg_text;
}				t_msgbuf;

/*
** get_msgbuf initialize new msgbuf
*/
t_msgbuf		get_msgbuf();

#endif
