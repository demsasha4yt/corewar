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

typedef struct s_token
{
	char *label;
	char *command;
	char *arg1;
	char *arg2;
	char *arg3;
	int arg_nu;
	struct s_token *next;
} t_token;

typedef struct	s_asm
{
	int fd_r;
	int fd_w;
	char	*file_name;
	char	*name;
	char	*comment;
	int name_s;
	struct s_token *first;
	//0 - не задан
	//1 - задается сейчас
	//2 - задан
	int comment_s;
	char	*file_path;
	int 	current_line;
	int 	current_column;
	char	*label;
	char	*output;

	t_list	*cmds;
}				t_asm;

void parse_p1(t_asm *asm_ms);
char *asm_read_cycle(t_asm *asm_ms);
void asm_error(int er_nu);
void	ft_start(char *file, t_asm *asm_ms, int fd);
int	is_space(char **str);
int	check_name_comment(char *str1, t_asm *asm_ms);


#endif
