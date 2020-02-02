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

int	_is_label_char(char c)
{
	int i;

	i = 0;
	while(LABEL_CHARS[i])
	{
		if(c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

int _is_number_char(char c)
{
	int i;

	i = 27;
	while(LABEL_CHARS[i])
	{
		if(c == LABEL_CHARS[i])
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

int _save_info(t_asm *asm_ms, char *str, t_token *current, int last)
{
	int size;
	if(current->code_operation == 16)
	{
		last > 3 ? error("invalid T_REG") : 0;
		current->itog = ft_memalloc(sizeof(char) * 3); ///включает +1 под код типа арг
		current->cod_tipa_argumentov = shell_arg_byte(current->type_args);
		current->itog[0] = (char)current->code_operation;
		current->itog[1] = current->cod_tipa_argumentov;
		current->command_size = 3;
		asm_ms->current_byte += 3;
		current->arg1 = ft_strsub(str, 0, last);
		current->type_args_byte = shell_arg_byte(current->type_args);
	}
	else
	{
		size = current->code_operation == 1 ? 4 : 2;
		current->itog = ft_memalloc(sizeof(char) * size + 1); ///+1 под код типа не нужен
		current->itog[0] = (char) (current->code_operation);
		current->command_size += size + 1;
		asm_ms->current_byte += size + 1;
		current->arg1 = ft_strsub(str, 0, last);
	}
	return (0);
}

int _one_argument(t_asm *asm_ms, char *str, t_token *current)///проверка %0 - T_DIR с числом
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (str[i] && str[i] == DIRECT_CHAR)
		i++;
	else if(str[i] && str[i] == LABEL_CHARS[17] && _is_number_char(str[i + 1])) ///если регистр 'r'
	{
		i++;
		_is_number_char(str[i]) ? 0 : error("wrong symbols");
		while (str[i] && _is_number_char(str[i]))
			i++;
		j = i;
		is_spacei(str, &i);
		if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
			error("symbols after");
		_save_info(asm_ms, str, current, j);
		exit (0);
	}
	else
		error("wrong separator");
	if (str[i] && str[i] == LABEL_CHAR)
	{
		i++;
		while (str[i] && _is_label_char(str[i]))
			i++;
		j = i;
		is_spacei(str, &i);
		if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
			error("symbols after");
	}
	else if ((str[i] == '-' || _is_number_char(str[i])) && str[i])
	{
		str[i] == '-' && ((!str[i + 1] || !_is_number_char (str[i + 1]))) ? error("error symbols afetr -") : i++;
		//i++; ///в тернарник!!!
		while (str[i] && _is_number_char(str[i]))
			i++;
		j = i;
		is_spacei(str, &i);
		if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
			error("symbols after");
	}
	else
		error("lexical");
	_save_info(asm_ms, str, current, j);
	exit (0);
}

void	_direct_size(t_asm *asm_ms, char *str, t_token *current)
{
	if (current->code_operation == 10 || current->code_operation == 11 || current->code_operation == 14)
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

void	_indirect_size(t_asm *asm_ms, char *str, t_token *current)
{
	if(current->size1 == 0)
		current->size1 = 4;
	else if(current->size2 == 0)
		current->size2 = 4;
	else if(current->size3 == 0)
		current->size3 = 4;
}

void	_register_size(t_asm *asm_ms, char *str, t_token *current)
{
	if(current->size1 == 0)
		current->size1 = 1;
	else if(current->size2 == 0)
		current->size2 = 1;
	else if(current->size3 == 0)
		current->size3 = 1;
}

void _arg(char *str, t_token *current, int start, int end)
{
	if(!current->arg1)
		current->arg1 = ft_strsub2(str, start, end);
	else if(!current->arg2)
		current->arg2 = ft_strsub2(str, start, end);
	else if(!current->arg3)
		current->arg3 = ft_strsub2(str, start, end);
}

int		_two_three_arguments(t_asm *asm_ms, char *str, t_token *current)
{
	int a;
	int i;
	int j;
	int start;

	a = 0;
	i = 0;
	while (a < current->arg_numbers)
	{
		is_spacei(str, &i);
		if(str[i] && str[i] == DIRECT_CHAR) /////////////  %...   ////////////
		{
			start = i;
			i++;
			if(str[i] && (str[i] == '-' || _is_number_char(str[i])))////// %5 or %-5 //////////
			{
				str[i] == '-' && ((!str[i + 1] || !_is_number_char (str[i + 1]))) ? error("error symbols afetr -") : i++;
				while (str[i] && _is_number_char(str[i]))
					i++;
				j = i;
				_direct_size(asm_ms, str, current);
				_arg(str, current, start, j);
				is_spacei(str, &i);
				if(a + 1 == current->arg_numbers)
				{
					is_spacei(str, &i);
					if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
						error("symbols after");
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
				while (str[i] && _is_label_char(str[i]))
					i++;
				j = i;
				_direct_size(asm_ms, str, current);
				_arg(str, current, start, j);
				is_spacei(str, &i);
				if(a + 1 == current->arg_numbers)
				{
					is_spacei(str, &i);
					if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
						error("symbols after");
				}
				else if(str[i++] == SEPARATOR_CHAR)
				{
					a++;
					continue;
				}
			}
			else
				error("lexical");

		}
		else if(str[i] && str[i] == LABEL_CHAR) ///////   :   ///////
		{
			start = i;
			i++;
			while (str[i] && _is_label_char(str[i]))
				i++;
			j = i;
			_direct_size(asm_ms, str, current);
			_arg(str, current, start, j);
			is_spacei(str, &i);
			if(a + 1 == current->arg_numbers)
			{
				is_spacei(str, &i);
				if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
					error("symbols after");
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
			_is_number_char(str[i]) ? 0 : error("wrong symbols");
			while (str[i] && _is_number_char(str[i]))
				i++;
			j = i;
			j - start > 3 ? error("invalid T_REG") : 0;
			_register_size(asm_ms, str, current);
			_arg(str, current, start, j);
			is_spacei(str, &i);
			if(a + 1 == current->arg_numbers)
			{
				is_spacei(str, &i);
				if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
					error("symbols after");
			}
			else if(str[i++] == SEPARATOR_CHAR)
			{
				a++;
				continue;
			}
		}
		else if(str[i] && (str[i] == '-' || _is_number_char(str[i]))) //////   from -1000... to 1000...   //////
		{
			start = i;
			str[i] == '-' && ((!str[i + 1] || !_is_number_char (str[i + 1]))) ? error("error symbols afetr -") : i++;
			while (str[i] && _is_number_char(str[i]))
				i++;
			j = i;
			_direct_size(asm_ms, str, current);
			_arg(str, current, start, j);
			is_spacei(str, &i);
			if(a + 1 == current->arg_numbers)
			{
				is_spacei(str, &i);
				if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
					error("symbols after");
			}
			else if(str[i++] == SEPARATOR_CHAR)
			{
				a++;
				continue;
			}
		}
		else
			error("lexical");
		a++;
	}

	return (0);
}

int _save_all_info(t_asm *asm_ms, char *str, t_token *current)
{
	if (1)
	{

	}
}