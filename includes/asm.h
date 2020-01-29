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
typedef struct s_label
{
	char *name;
	int byte;
	struct s_label *next;
} t_label;

typedef struct s_token
{
	char *command;
	char *arg1;
	char *arg2;
	char *arg3;
	int size1;
	int size2;
	int size3;
	int type_args;
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
	struct s_label *label;
	int current_byte;
	//
	int comment_s;
	char	*file_path;
	int 	current_line;
	int 	current_column;
	char	*output;
	t_op **op;
	t_list	*cmds;
}				t_asm;

void parse_p1(t_asm *asm_ms);
char *asm_read_cycle(t_asm *asm_ms);
void asm_error(int er_nu);
void	ft_start(char *file, t_asm *asm_ms, int fd);
int	is_space(char **str);
int is_comment(char *str);
int	check_name_comment(char *str1, t_asm *asm_ms);
void init_asm_ms(t_asm *asm_ms);
int is_blank(char *str);
t_token *init_token_p1(t_asm *asm_ms);
int init_label(char **str, t_label *label, t_asm *asm_ms, int i);
int check_label(char **str, t_asm *asm_ms);
void write_champ_code(t_asm *asm_ms);
void create_command(t_token *token);
int create_reg_arg(t_token *token, int byte, int arg_nu, t_asm *asm_ms);
int create_dir_arg(t_token *token, int byte, int arg_nu, t_asm *asm_ms);
int create_ind_arg(t_token *token, int byte, int arg_nu, t_asm *asm_ms);
void create_args(t_token *token, t_asm *asm_ms);
int count_label(t_asm *asm_ms, char *str, int byte);
int add(t_token *token, int to_add, int byte, int size);

#endif
