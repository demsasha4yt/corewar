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
		current->arg1 = ft_memalloc(sizeof(char) * 3);
		current->arg1[0] = (char)(current->code_operation);
		current->command_size = 3;
		asm_ms->current_byte += 3;
		current->arg1 = ft_strsub(str, 0, last);
	}
	else
	{
		size = current->code_operation == 1 ? 4 : 2;
		current->arg1 =
			ft_memalloc(sizeof(char) * size + 1); ///+1 под код типа не нужен
		current->arg1[0] = (char) (current->code_operation);
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
	if (str[i++] == LABEL_CHAR)
	{
		//i++;
		while (str[i] && _is_label_char(str[i]))
			i++;
		j = i;
		is_spacei(str, &i);
		if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
			error("symbols after");
	}
	else if ((str[i] == '-' || _is_number_char(str[i])) && str[i])
	{
		str[i] == '-' && ((!str[i + 1] || !_is_number_char (str[i + 1]))) ? error("error symbols afetr -") : 0;
		i++;
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
//	else if (*str >= '0' && *str <= '9')
//	{
//
//	}
//	while (str[i] && str[i] != ' ' && str[i] != '\t')
//	{
//		if(str[i] >= '0' && str[i] <= '9')
//		{
//			i++;
//			continue;
//		}
//		else
//			error("wrong argument");
//	}
//	str += i;
//	is_space(&str);
//	if(*str != COMMENT_CHAR && *str != ALT_COMMENT_CHAR && *str != '\0')
//		error("symbols after");
