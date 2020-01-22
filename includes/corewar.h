/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:27:46 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/22 16:32:10 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"

typedef	struct	s_ply
{
	int				ident_number;
	char			*name;
	char			*comment;
	int				code_size;
	int				*ply_code;
	char			*file_path;
	struct s_ply	*next;
	struct s_ply	*prev;
}				t_ply;



typedef struct	s_cw
{
	t_ply		*players;
	
}				t_cw;


#endif