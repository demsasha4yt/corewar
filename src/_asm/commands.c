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

size_t	digit_count(unsigned long nb, int base)
{
	size_t	i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long long int value, int base)
{
	char	*ret;
	char	*tab_base;
	int		taille;
	int		i;

	tab_base = "0123456789abcdef";
	if (value == 0)
		return ("0");
	taille = digit_count(value, base);
	if (!(ret = (char *)malloc(sizeof(char) * (taille + 1))))
		return (NULL);
	i = 1;
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	ret[taille] = '\0';
	return (ret);
}



int _save_info(t_asm *asm_ms, char *str, t_token *current, int last)
{
	int size = !ft_strcmp(current->name, "live") ? 4 : 2;
	current->arg1 = ft_memalloc(sizeof(char) * size + 1); ///+1 под код типа не нужен
	current->arg1[0] = (char)(current->code_operation);
	current->command_size += size + 1;
	asm_ms->current_byte += size + 1;
	current->arg1 = ft_strsub(str, 0, last);
}

int _live_check_fork_lfork(t_asm *asm_ms, char *str, t_token *current)///проверка %0 - T_DIR с числом
{
	int i;
	int j;

	i = 0;
	if (str[i] && str[i] == DIRECT_CHAR)
		i++;
	else
		error("wrong separator");
	if (str[i] == LABEL_CHAR)
	{
		i++;
		while (str[i] && _is_label_char(str[i]))
			i++;
		j = i;
		is_spacei(str, &i);
		if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i] != '\0')
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
		if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i] != '\0')
			error("symbols after");
	}
	else
		error("lexical");
	_save_info(asm_ms, str, current, j);
	return (0);
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


void _ld_check(t_asm *asm_ms, char *str, t_token *current)
{
	int i = 0;
	if(*str && *str == DIRECT_CHAR)
		str += 1;
}


//
//void _st()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}
//
//void _add()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}
//
//void _sub()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}
//
//void _and()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}
//
//void _or()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}
//
//void _xor()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}
//
//void _zjmp()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}
//
//void _ldi()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}
//
//void _sti()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}
//
//void _fork()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}
//
//void _lld()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}
//
//void _lldi()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}
//
//void _lfork()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}
//
//void _aff()
//{
//	unsigned dir;
//	int code;
//
//	dir = 2;
//	code = 0x0C;
//
//
//}