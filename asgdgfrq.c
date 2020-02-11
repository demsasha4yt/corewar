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

int is_number_char(char c)
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

void is_spacei(const char *s, int *i)
{
	while(s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
		*i += 1;
}

int save_info_one_arg(t_asm *asm_ms, char *str, t_token *current, int last)
{
	int size;

	if (current->code_operation == 16)
	{
		current->arg1 = ft_strsub(str, 0, last);
		current->arg1[0] != 'r' ? asm_error(9, current->current_line, asm_ms) : 0;
		last > 3 ? asm_error(14, current->current_line, asm_ms) : 0;
		if (!(current->output = ft_memalloc(sizeof(char) * 3)))
			asm_error(4, current->current_line, asm_ms);
		current->output[0] = (char)current->code_operation;
		current->output[1] = shell_arg_byte(current->type_args);
		current->command_size = 3;
		asm_ms->current_byte += 3;
		current->size1 = asm_ms->current_byte - 3;
		current->len = 3;
	}
	else
	{
		current->arg1 = ft_strsub(str, 0, last);
		current->arg1[0] != '%' ? asm_error(9, current->current_line, asm_ms) : 0;
		size = current->code_operation == 1 ? 4 : 2;
		if (!(current->output = ft_memalloc(sizeof(char) * size + 1)))
			asm_error(4, current->current_line, asm_ms);
		current->output[0] = (char) (current->code_operation);
		current->command_size += size + 1;
		asm_ms->current_byte += size + 1;
		current->size1 = asm_ms->current_byte - size - 1;
		current->type_args = 0;
		current->len = size + 1;
	}
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

int one_argument(t_asm *asm_ms, char *str, t_token *current)
{
	t_var var;

	ft_bzero(&var, sizeof(t_var));
	if (str[var.i] && str[var.i] == DIRECT_CHAR)
		var.i++;
	else if (str[var.i] && str[var.i] == LABEL_CHARS[17] && is_number_char(str[var.i
		+ 1]))
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

void	_direct_size(t_token *current)
{
	if (current->code_operation == 10 || current->code_operation == 11 ||
		current->code_operation == 14)
	{
		if(current->size1 == 0)
			current->size1 = 2;
		else if(current->size2 == 0)
			current->size2 = 2;
		else if(current->size3 == 0)
			current->size3 = 2;
	}
	else
	{
		if(current->size1 == 0)
			current->size1 = 4;
		else if(current->size2 == 0)
			current->size2 = 4;
		else if (current->size3 == 0)
			current->size3 = 4;
	}
}

void	_indirect_size(t_token *current)
{
	if(current->size1 == 0)
		current->size1 = 2;
	else if(current->size2 == 0)
		current->size2 = 2;
	else if(current->size3 == 0)
		current->size3 = 2;
}

void	_register_size(t_token *current)
{
	if(current->size1 == 0)
		current->size1 = 1;
	else if(current->size2 == 0)
		current->size2 = 1;
	else if(current->size3 == 0)
		current->size3 = 1;
}

void    _check_arg(t_token *current, char *arg, int num)
{
	t_asm tmp;

	tmp.file_name = "42.cor";///error name pls
	if (g_op_tab[current->index].args_types[num] == 1)
		arg[0] != 'r' ? asm_error(9+num, current->current_line, &tmp) : 0;
	else if (g_op_tab[current->index].args_types[num] == 2)
		arg[0] != '%' ? asm_error(9+num, current->current_line, &tmp) : 0;
	else if (g_op_tab[current->index].args_types[num] == 3)
		arg[0] == 'r' || arg[0] == '%' ? 0 : asm_error(9+num, current->current_line, &tmp);
	else if (g_op_tab[current->index].args_types[num] == 4)
		arg[0] != 'r' && arg[0] != '%' ? 0 : asm_error(9+num, current->current_line, &tmp);
	else if (g_op_tab[current->index].args_types[num] == 5)
		arg[0] != '%' ? 0 : asm_error(9+num, current->current_line, &tmp);
	else if (g_op_tab[current->index].args_types[num] == 6)
		arg[0] != 'r' ? 0 : asm_error(9+num, current->current_line, &tmp);
}

void _arg(char *str, t_token *current, int start, int end)
{
	if (!current->arg1)
	{
		current->arg1 = ft_strsub2(str, start, end);
		_check_arg(current, current->arg1, 0);
	}
	else if (!current->arg2)
	{
		current->arg2 = ft_strsub2(str, start, end);
		_check_arg(current, current->arg2, 1);
	}
	else if (!current->arg3)
	{
		current->arg3 = ft_strsub2(str, start, end);
		_check_arg(current, current->arg3, 2);
	}
}

int		two_three_arguments(t_asm *asm_ms, char *str, t_token *current)
{
	int a;
	int i;
	int j;
	int start;

	a = 0;
	i = 0;
	while (a < current->arg_numbers)
	{
		j = 0;
		is_spacei(str, &i);
		if(str[i] && str[i] == DIRECT_CHAR) /////////////  %...   ////////////
		{
			start = i;
			i++;
			j++;
			if(str[i] && (str[i] == '-' || _is_number_char(str[i])))////// %5 or %-5 //////////
			{
				str[i] == '-' ? j++ : 0;
				str[i] == '-' && ((!str[i + 1] || !_is_number_char (str[i + 1]))) ? asm_error(14 + a, current->current_line, asm_ms) : 0;
				str[i] == '-' ? i++ : 0;
				while (str[i] && _is_number_char(str[i]))
				{
					i++;
					j++;
				}
				_direct_size(current);
				_arg(str, current, start, j);
				is_spacei(str, &i);
				if(a + 1 == current->arg_numbers)
				{
					is_spacei(str, &i);
					if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
						asm_error(14 + a, current->current_line, asm_ms);
				}
				else if(str[i++] == SEPARATOR_CHAR)
				{
					a++;
					continue;
				}
			}
			else if(str[i] && str[i] == LABEL_CHAR)//////////   %:  ////////////
			{
				i++;
				j++;
				while (str[i] && _is_label_char(str[i]))
				{
					i++;
					j++;
				}
				_direct_size(current);
				_arg(str, current, start, j);
				is_spacei(str, &i);
				if(a + 1 == current->arg_numbers)
				{
					is_spacei(str, &i);
					if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
						asm_error(14 + a, current->current_line, asm_ms);
				}
				else if(str[i++] == SEPARATOR_CHAR)
				{
					a++;
					continue;
				}
			}
			else
				asm_error(14 + a, current->current_line, asm_ms);

		}
		else if(str[i] && str[i] == LABEL_CHAR) ///////   :   ///////
		{
			start = i;
			i++;
			j++;
			while (str[i] && _is_label_char(str[i]))
			{
				i++;
				j++;
			}
			_indirect_size(current);
			_arg(str, current, start, j);
			is_spacei(str, &i);
			if(a + 1 == current->arg_numbers)
			{
				is_spacei(str, &i);
				if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
					asm_error(14 + a, current->current_line, asm_ms);
			}
			else if(str[i++] == SEPARATOR_CHAR)
			{
				a++;
				continue;
			}
		}
		else if(str[i] && str[i] == REGISTER_CHAR) ///////   r99   ////////
		{
			start = i;
			i++;
			j++;
			_is_number_char(str[i]) ? 0 : asm_error(14 + a, current->current_line, asm_ms);
			while (str[i] && _is_number_char(str[i]))
			{
				i++;
				j++;
			}
			j > 3 ? asm_error(14 + a, current->current_line, asm_ms) : 0;
			_register_size(current);
			_arg(str, current, start, j);
			is_spacei(str, &i);
			if(a + 1 == current->arg_numbers)
			{
				is_spacei(str, &i);
				if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
					asm_error(14 + a, current->current_line, asm_ms);
			}
			else if(str[i++] == SEPARATOR_CHAR)
			{
				a++;
				continue;
			}
		}
		else if(str[i] && (str[i] == '-' || _is_number_char(str[i]))) //////   from -1000... to 1000...   //////
		{
			j++;
			start = i;
			str[i] == '-' ? j++ : 0;
			str[i] == '-' && ((!str[i + 1] || !(_is_number_char) (str[i + 1]))) ? asm_error(14 + a, current->current_line, asm_ms) : i++;
			while (str[i] && _is_number_char(str[i]))
			{
				i++;
				j++;
			}
			_indirect_size(current);
			_arg(str, current, start, j);
			is_spacei(str, &i);
			if(a + 1 == current->arg_numbers)
			{
				is_spacei(str, &i);
				if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
					asm_error(14 + a, current->current_line, asm_ms);
			}
			else if(str[i++] == SEPARATOR_CHAR)
			{
				a++;
				continue;
			}
		}
		else
			asm_error(14 + a, current->current_line, asm_ms);
		a++;
	}
	save_all_info(asm_ms, current);
	return (0);
}

int _size_code(int size, t_token *current)
{
	if (current->arg1)
	{
		if(current->arg1[0] == '%')
			size += 200;
		else if(current->arg1[0] == 'r')
			size += 100;
		else
			size += 300;
	}
	if (current->arg2)
	{
		if(current->arg2[0] == '%')
			size += 20;
		else if(current->arg2[0] == 'r')
			size += 10;
		else
			size += 30;
	}
	if (current->arg3)
	{
		if(current->arg3[0] == '%')
			size += 2;
		else if(current->arg3[0] == 'r')
			size += 1;
		else
			size += 3;
	}
	return (size);
}

void save_all_info(t_asm *asm_ms, t_token *current)
{
	int size;

	size = 0;
	size = _size_code(size, current);
	current->type_args = size;
	current->arg_type_code = shell_arg_byte(size);
	if(!(current->output = ft_memalloc(sizeof(char) * 1 + 1 + (current->size1 + current->size2 + current->size3))))
		asm_error(4, current->current_line, asm_ms);
	current->output[0] = (char)current->code_operation;
	current->output[1] = current->arg_type_code;
	asm_ms->current_byte += 1 + 1 + (current->size1 + current->size2 + current->size3);
	current->len = 1 + 1 + (current->size1 + current->size2 + current->size3);
	current->size1 = asm_ms->current_byte - current->size1 - current->size2 - current->size3 - 2;
	current->size2 = current->size1;
	current->size3 = current->size1;
}
