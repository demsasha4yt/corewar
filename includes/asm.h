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

typedef  struct s_label
{
	char *name;
	int byte;
}t_label;

typedef struct s_token
{
	char *name;
	char *itog;
	char cod_tipa_argumentov;
	int code_operation;
	int type_args; ///230 если надо - смотреть в таблице!
	int type_args_byte;
	int arg_numbers; ///
	char  *arg1; ///записать %:lebel00
	char  *arg2;
	char  *arg3;
	int size1;
	int size2;
	int size3;
	int command_size; ///длина выделяемой строки
	//int byte;
	int index;
	struct s_token *next;
} t_token;

typedef struct s_op
{
	char *name;
	int args_num;
	int args_types[3];
	int code;
	int cycles;
	char *description;
	int args_types_code;
	int t_dir_size;
} t_op;

extern t_op op_tab[17];

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
	int current_byte; ///+размер команды
	t_list	*cmds;
}				t_asm;


void	error(char *str);
void	parse_p1(t_asm *asm_ms);
char	*asm_read_cycle(t_asm *asm_ms);
void	asm_error(int er_nu);
void	ft_start(char *file, t_asm *asm_ms, int fd);
int		is_space(char **str);
int		is_comment(char *str);
int		check_name_comment(char *str1, t_asm *asm_ms);
int		is_blank(char *str);
int		check_command(t_asm *asm_ms, char *str, t_token *current);
int 	_one_argument(t_asm *asm_ms, char *str, t_token *current);
char 	shell_arg_byte(int type_args);
int		_two_three_arguments(t_asm *asm_ms, char *str, t_token *current);


#endif
