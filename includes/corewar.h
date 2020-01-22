/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:27:46 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/22 17:26:40 by bharrold         ###   ########.fr       */
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

typedef struct	s_arena
{
	int			*data;
} 				t_arena;

typedef struct	s_carry
{
	int				num;
	int				flag;
	int				live_cycle;
	int				cycles_left;
	int				position;
	int				registries[REG_NUMBER];
	struct s_carry	*next;
	struct s_carry	*prev;
}				t_carry;


typedef struct	s_cw
{
	int			count_players;
	t_arena		*arena;
	t_carry		*carries;
	t_ply		*players;
}				t_cw;

void	terminate(int code, t_cw *cw){
void	initialize_cw(t_cw *cw);
void	destroy_cw(t_cw *cw);


#endif