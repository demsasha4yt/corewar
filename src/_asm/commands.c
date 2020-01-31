#include "asm.h"

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
	{
		*i += 1;
	}
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

int		_two_three_arguments(t_asm *asm_ms, char *str, t_token *current)
{
	int a;
	int i;
	int j;

	a = 0;
	i = 0;
	j = 0;
	while (a < op_tab[current->index].args_num)
	{
		if(str[i] && str[i] == DIRECT_CHAR) ///%
		{
			i++;
			if(str[i] && (str[i] == '-' || _is_number_char(str[i])))
			{
				str[i] == '-' && ((!str[i + 1] || !_is_number_char (str[i + 1]))) ? error("error symbols afetr -") : i++;
				while (str[i] && _is_label_char(str[i]))
					i++;
				j = i;
				is_spacei(str, &i);

			}
			else if(str[i] && _is_number_char(str[i]))
			{

			}
			else
				error("lexical");

		}
		else if(str[i] && str[i] == LABEL_CHAR) ///:
		{

		}
		else if(str[i] && str[i] == REGISTER_CHAR) ///r
		{

		}
		else if(str[i] && _is_number_char(str[i])) ///0-9
		{

		}
		else
			error("lexical");
		a++;
	}
	return (0);
}