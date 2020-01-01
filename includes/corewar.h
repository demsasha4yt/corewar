/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:27:46 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/01 18:56:11 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"


typedef	struct	s_ply
{
	char		*path;
	int			name;
	char		*cname;
	
}				t_ply;

typedef struct	s_vm
{
	t_ply		**players;
}				t_vm;

t_vm			*create_vm();
void			destroy_vm(t_vm **vm);

#endif