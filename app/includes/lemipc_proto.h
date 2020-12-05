/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_proto.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:53:18 by bharrold          #+#    #+#             */
/*   Updated: 2020/12/05 16:04:28 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_PROTO_H
# define LEMIPC_PROTO_H

# include "lemipc_player.h"
# include "lemipc_msg.h"

# define PROTO_ENTER	1
# define PROTO_REQ		2
# define PROTO_YES		3
# define PROTO_NO		4
# define PROTO_KICK		5
# define PROTO_DONE		6
# define PROTO_EXIT		7

# define HANDLERS_CNT	7

#endif
