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

	char	*label;
	char	*output;
	t_list	*cmds;
}				t_asm;

t_asm		*create_asm();
void		destroy_asm(t_asm **_asm);

void		validate_format(t_asm *_asm);
void		validate_name(char *line, t_asm *_asm);
void		validate_name_second_str(char *line, t_asm *_asm);
void		validate_name_last_str(char *line, t_asm *_asm);
void		validate_comment(char *line, t_asm *_asm);
void		validate_comment_second_str(char *line, t_asm *_asm);
void		validate_comment_last_str(char *line, t_asm *_asm);
int			is_comment_ch(char *line);

void		read_file(t_asm *_asm);
void		read_name(char *line, int fd, t_asm *_asm);
void		read_comment(char *line, int fd, t_asm *_asm);
void		read_cmds(char *line, int fd, t_asm *_asm);

void		terminate(int code, t_asm **_asm);

#endif
