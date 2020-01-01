/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:27:46 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/01 20:30:00 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include <limits.h>

# include "libft.h"
# include "op.h"

typedef struct	s_asm
{
	char	*file_path;
	char	*name;
	char	*comment;
	char	*label;
	char	*output;
}				t_asm;

t_asm		*create_asm();
void		destroy_asm(t_asm **_asm);

void		validate_format(t_asm *_asm);
void		validate_name(char *line, t_asm *_asm);
void		validate_comment(char *line, t_asm *_asm);

void		read_file(t_asm *_asm);
void		read_name(char *line, int fd, t_asm *_asm);
void		read_comment(char *line, int fd, t_asm *_asm);

void		terminate(int code, t_asm **_asm);

#endif