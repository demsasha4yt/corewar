/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:27:46 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/17 21:42:14 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include <limits.h>
#include <fcntl.h>
# include "libft.h"
# include "op.h"

typedef struct	s_asm
{
	int fd_r;
	int fd_w;
	char	*file_name;
	char	*name;
	char	*comment;

	//
	char	*file_path;
	int 	current_line;
	int 	current_column;
	char	*label;
	char	*output;
	t_list	*cmds;
}				t_asm;

void parse_p1(char *file, t_asm *asm_ms);
char *asm_read_cycle(t_asm *asm_ms);
void asm_error(int er_nu);
void	ft_start(char *file, t_asm *asm_ms, int fd);

#endif
