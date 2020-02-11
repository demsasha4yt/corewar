/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 00:02:38 by kbessa            #+#    #+#             */
/*   Updated: 2020/02/12 00:02:39 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_strsub2(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!(new = ft_strnew(len)))
		return (NULL);
	if (s)
		while (i < len)
		{
			new[i] = s[start + i];
			i++;
		}
	return (new);
}

int	is_label_char(char c)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i])
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_number_char(char c)
{
	int i;

	i = 27;
	while (LABEL_CHARS[i])
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

void	is_spacei(const char *s, int *i)
{
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
		*i += 1;
}

void	one_arg_aff(t_asm *asm_ms, t_token *cur, int last, char *str)
{
	cur->arg1 = ft_strsub(str, 0, last);
	cur->arg1[0] != 'r' ? asm_error(9, cur->current_line, asm_ms) : 0;
	last > 3 ? asm_error(14, cur->current_line, asm_ms) : 0;
	cur->output = ft_memalloc(sizeof(char) * 3);
	cur->output[0] = (char)cur->code_operation;
	cur->output[1] = shell_arg_byte(cur->type_args);
	cur->command_size = 3;
	asm_ms->current_byte += 3;
	cur->size1 = asm_ms->current_byte - 3;
	cur->len = 3;
}

void	one_arg_dir(t_asm *asm_ms, t_token *cur, int last, char *str)
{
	int size;

	cur->arg1 = ft_strsub(str, 0, last);
	cur->arg1[0] != '%' ? asm_error(9, cur->current_line, asm_ms) : 0;
	size = cur->code_operation == 1 ? 4 : 2;
	cur->output = ft_memalloc(sizeof(char) * size + 1);
	cur->output[0] = (char)(cur->code_operation);
	cur->command_size += size + 1;
	asm_ms->current_byte += size + 1;
	cur->size1 = asm_ms->current_byte - size - 1;
	cur->len = size + 1;
}

int	save_info_one_arg(t_asm *asm_ms, char *str, t_token *cur, int last)
{
	if (cur->code_operation == 16)
		one_arg_aff(asm_ms, cur, last, str);
	else
		one_arg_dir(asm_ms, cur, last, str);
	return (0);
}

void	one_arg_register(char *str, t_asm *asm_ms, t_token *cur, t_var *var)
{
	var->i++;
	is_number_char(str[var->i]) ? 0 : asm_error(14, cur->current_line, asm_ms);
	while (str[var->i] && is_number_char(str[var->i]))
		var->i++;
	var->j = var->i;
	is_spacei(str, &var->i);
	if (str[var->i] != COMMENT_CHAR && str[var->i] != ALT_COMMENT_CHAR &&
			str[var->i])
		asm_error(14, cur->current_line, asm_ms);
	save_info_one_arg(asm_ms, str, cur, var->j);
}

void	one_arg_dir_label(char *str, t_asm *asm_ms, t_token *cur, t_var *var)
{
	var->i++;
	while (str[var->i] && is_label_char(str[var->i]))
		var->i++;
	var->j = var->i;
	is_spacei(str, &var->i);
	if (str[var->i] != COMMENT_CHAR && str[var->i] != ALT_COMMENT_CHAR &&
			str[var->i])
		asm_error(14, cur->current_line, asm_ms);
}

void	one_arg_dir_number(char *str, t_asm *asm_ms, t_token *cur, t_var *var)
{
	str[var->i] == '-' && ((!str[var->i + 1] ||
		!(is_number_char(str[var->i + 1])))) ?
			asm_error(14, cur->current_line, asm_ms) : var->i++;
	while (str[var->i] && is_number_char(str[var->i]))
		var->i++;
	var->j = var->i;
	is_spacei(str, &var->i);
	if (str[var->i] != COMMENT_CHAR && str[var->i] != ALT_COMMENT_CHAR &&
			str[var->i])
		asm_error(14, cur->current_line, asm_ms);
}

int	one_argument(t_asm *asm_ms, char *str, t_token *current)
{
	t_var var;

	ft_bzero(&var, sizeof(t_var));
	if (str[var.i] && str[var.i] == DIRECT_CHAR)
		var.i++;
	else if (str[var.i] && str[var.i] == LABEL_CHARS[17] &&
		is_number_char(str[var.i + 1]))
	{
		one_arg_register(str, asm_ms, current, &var);
		return (0);
	}
	else
		asm_error(14, current->current_line, asm_ms);
	if (str[var.i] && str[var.i] == LABEL_CHAR)
		one_arg_dir_label(str, asm_ms, current, &var);
	else if ((str[var.i] == '-' || is_number_char(str[var.i])) && str[var.i])
		one_arg_dir_number(str, asm_ms, current, &var);
	else
		asm_error(14, current->current_line, asm_ms);
	save_info_one_arg(asm_ms, str, current, var.j);
	return (0);
}

void	direct_size(t_token *current)
{
	if (current->code_operation == 10 || current->code_operation == 11 ||
		current->code_operation == 14)
	{
		if (current->size1 == 0)
			current->size1 = 2;
		else if (current->size2 == 0)
			current->size2 = 2;
		else if (current->size3 == 0)
			current->size3 = 2;
	}
	else
	{
		if (current->size1 == 0)
			current->size1 = 4;
		else if (current->size2 == 0)
			current->size2 = 4;
		else if (current->size3 == 0)
			current->size3 = 4;
	}
}

void	indirect_size(t_token *current)
{
	if (current->size1 == 0)
		current->size1 = 2;
	else if (current->size2 == 0)
		current->size2 = 2;
	else if (current->size3 == 0)
		current->size3 = 2;
}

void	register_size(t_token *current)
{
	if (current->size1 == 0)
		current->size1 = 1;
	else if (current->size2 == 0)
		current->size2 = 1;
	else if (current->size3 == 0)
		current->size3 = 1;
}

void	check_arg(t_token *current, const char *arg, int num, t_asm *asm_ms)
{
	if (g_op_tab[current->index].args_types[num] == 1)
		arg[0] != 'r' ? asm_error(9 + num, current->current_line, asm_ms) : 0;
	else if (g_op_tab[current->index].args_types[num] == 2)
		arg[0] != '%' ? asm_error(9 + num, current->current_line, asm_ms) : 0;
	else if (g_op_tab[current->index].args_types[num] == 3)
		arg[0] == 'r' || arg[0] == '%' ? 0 :
			asm_error(9 + num, current->current_line, asm_ms);
	else if (g_op_tab[current->index].args_types[num] == 4)
		arg[0] != 'r' && arg[0] != '%' ? 0 :
			asm_error(9 + num, current->current_line, asm_ms);
	else if (g_op_tab[current->index].args_types[num] == 5)
		arg[0] != '%' ? 0 : asm_error(9 + num, current->current_line, asm_ms);
	else if (g_op_tab[current->index].args_types[num] == 6)
		arg[0] != 'r' ? 0 : asm_error(9 + num, current->current_line, asm_ms);
}

void	save_arguments(char *str, t_token *current, t_var *var, t_asm *asm_ms)
{
	if (!current->arg1)
	{
		current->arg1 = ft_strsub2(str, var->start, var->j);
		check_arg(current, current->arg1, 0, asm_ms);
	}
	else if (!current->arg2)
	{
		current->arg2 = ft_strsub2(str, var->start, var->j);
		check_arg(current, current->arg2, 1, asm_ms);
	}
	else if (!current->arg3)
	{
		current->arg3 = ft_strsub2(str, var->start, var->j);
		check_arg(current, current->arg3, 2, asm_ms);
	}
}

int	two_three_direct_number(char *str, t_token *cur, t_asm *asm_ms, t_var *var)
{
	str[var->i] == '-' ? var->j++ : 0;
	str[var->i] == '-' && ((!str[var->i + 1] || !is_number_char(str[var->i +
	1]))) ? asm_error(14 + var->a, cur->current_line, asm_ms) : 0;
	str[var->i] == '-' ? var->i++ : 0;
	while (str[var->i] && is_number_char(str[var->i]))
	{
		var->i++;
		var->j++;
	}
	direct_size(cur);
	save_arguments(str, cur, var, asm_ms);
	is_spacei(str, &var->i);
	if (var->a + 1 == cur->arg_numbers)
	{
		is_spacei(str, &var->i);
		if (!is_comment(&str[var->i]) && str[var->i])
			asm_error(14 + var->a, cur->current_line, asm_ms);
	}
	else if (str[var->i++] == SEPARATOR_CHAR)
	{
		var->a++;
		return (1);
	}
	return (0);
}

int	two_three_direct_label(char *str, t_token *curr, t_asm *asm_ms, t_var *var)
{
	var->i++;
	var->j++;
	while (str[var->i] && is_label_char(str[var->i]))
	{
		var->i++;
		var->j++;
	}
	direct_size(curr);
	save_arguments(str, curr, var, asm_ms);
	is_spacei(str, &var->i);
	if (var->a + 1 == curr->arg_numbers)
	{
		is_spacei(str, &var->i);
		if (!is_comment(&str[var->i]) && str[var->i])
			asm_error(14 + var->a, curr->current_line, asm_ms);
	}
	else if (str[var->i++] == SEPARATOR_CHAR)
	{
		var->a++;
		return (1);
	}
	return (0);
}

int	two_three_indirect_label(char *str, t_token *cur, t_asm *asm_ms, t_var *var)
{
	var->start = var->i++;
	var->j++;
	while (str[var->i] && is_label_char(str[var->i]))
	{
		var->i++;
		var->j++;
	}
	indirect_size(cur);
	save_arguments(str, cur, var, asm_ms);
	is_spacei(str, &var->i);
	if (var->a + 1 == cur->arg_numbers)
	{
		is_spacei(str, &var->i);
		if (!is_comment(&str[var->i]) && str[var->i])
			asm_error(14 + var->a, cur->current_line, asm_ms);
	}
	else if (str[var->i++] == SEPARATOR_CHAR)
	{
		var->a++;
		return (1);
	}
	return (0);
}

int	two_three_register(char *str, t_token *current, t_asm *asm_ms, t_var *var)
{
	var->start = var->i++;
	var->j++;
	is_number_char(str[var->i]) ? 0 : asm_error(14 + var->a,
		current->current_line, asm_ms);
	while (str[var->i] && is_number_char(str[var->i]))
	{
		var->i++;
		var->j++;
	}
	var->j > 3 ? asm_error(14 + var->a, current->current_line, asm_ms) : 0;
	register_size(current);
	save_arguments(str, current, var, asm_ms);
	is_spacei(str, &var->i);
	if (var->a + 1 == current->arg_numbers)
	{
		is_spacei(str, &var->i);
		if (!is_comment(&str[var->i]) && str[var->i])
			asm_error(14 + var->a, current->current_line, asm_ms);
	}
	else if (str[var->i++] == SEPARATOR_CHAR)
	{
		var->a++;
		return (1);
	}
	return (0);
}

int	two_three_indirect_num(char *str, t_token *cur, t_asm *asm_ms, t_var *var)
{
	var->j++;
	var->start = var->i;
	str[var->i] == '-' ? var->j++ : 0;
	str[var->i] == '-' && ((!str[var->i + 1] || !(is_number_char)(str[var->i +
	1]))) ? asm_error(14 + var->a, cur->current_line, asm_ms) : var->i++;
	while (str[var->i] && is_number_char(str[var->i]))
	{
		var->i++;
		var->j++;
	}
	indirect_size(cur);
	save_arguments(str, cur, var, asm_ms);
	is_spacei(str, &var->i);
	if (var->a + 1 == cur->arg_numbers)
	{
		is_spacei(str, &var->i);
		if (!is_comment(&str[var->i]) && str[var->i])
			asm_error(14 + var->a, cur->current_line, asm_ms);
	}
	else if (str[var->i++] == SEPARATOR_CHAR)
	{
		var->a++;
		return (1);
	}
	return (0);
}

int	two_three_direct(char *str, t_token *current, t_asm *asm_ms, t_var *var)
{
	var->start = var->i++;
	var->j++;
	if (str[var->i] && (str[var->i] == '-' || is_number_char(str[var->i])))
	{
		if (two_three_direct_number(str, current, asm_ms, var))
			return (1);
	}
	else if (str[var->i] && str[var->i] == LABEL_CHAR)
	{
		if (two_three_direct_label(str, current, asm_ms, var))
			return (1);
	}
	else
		asm_error(14 + var->a, current->current_line, asm_ms);
	return (0);
}

int	main_cycle_arguments(t_asm *asm_ms, char *str, t_token *current, t_var *var)
{
	is_spacei(str, &var->i);
	if (str[var->i] && str[var->i] == DIRECT_CHAR)
	{
		if (two_three_direct(str, current, asm_ms, var))
			return (1);
	}
	else if (str[var->i] && str[var->i] == LABEL_CHAR)
	{
		if (two_three_indirect_label(str, current, asm_ms, var))
			return (1);
	}
	else if (str[var->i] && str[var->i] == REGISTER_CHAR)
	{
		if (two_three_register(str, current, asm_ms, var))
			return (1);
	}
	else if (str[var->i] && (str[var->i] == '-' || is_number_char(str[var->i])))
	{
		if (two_three_indirect_num(str, current, asm_ms, var))
			return (1);
	}
	else
		asm_error(14 + var->a, current->current_line, asm_ms);
	var->a++;
	return (0);
}

int		two_three_arguments(t_asm *asm_ms, char *str, t_token *current)
{
	t_var var;

	ft_bzero(&var, sizeof(t_var));
	while (var.a < current->arg_numbers)
	{
		var.j = 0;
		if (main_cycle_arguments(asm_ms, str, current, &var))
			continue ;
	}
	save_all_info(asm_ms, current);
	return (0);
}

int	size_code(int size, t_token *current)
{
	if (current->arg1 && current->arg1[0] == 'r')
		size = 100;
	else if (current->arg1 && current->arg1[0] == '%')
		size = 200;
	else if (current->arg1)
		size = 300;
	if (current->arg2 && current->arg2[0] == 'r')
		size += 10;
	else if (current->arg2 && current->arg2[0] == '%')
		size += 20;
	else if (current->arg2)
		size += 30;
	if (current->arg3 && current->arg3[0] == 'r')
		size += 1;
	else if (current->arg3 && current->arg3[0] == '%')
		size += 2;
	else if (current->arg3)
		size += 3;
	return (size);
}

void	save_all_info(t_asm *asm_, t_token *cur)
{
	int size;

	size = 0;
	size = size_code(size, cur);
	cur->type_args = size;
	cur->output = ft_memalloc(sizeof(char) * 1 + 1 +
		(cur->size1 + cur->size2 + cur->size3));
	cur->output[0] = (char)cur->code_operation;
	cur->output[1] = shell_arg_byte(size);
	asm_->current_byte += 1 + 1 + (cur->size1 + cur->size2 + cur->size3);
	cur->len = 1 + 1 + (cur->size1 + cur->size2 + cur->size3);
	cur->size1 = asm_->current_byte - cur->size1 - cur->size2 - cur->size3 - 2;
	cur->size2 = cur->size1;
	cur->size3 = cur->size1;
}
