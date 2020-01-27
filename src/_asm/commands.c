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

int _live_check(char *str)///проверка %0 - T_DIR с числом
{
	if (*str && *str == DIRECT_CHAR)
		str += 1;
	else
		error("wrong separator");
	if (*str == LABEL_CHAR)
	{
		str += 1;
		while (*str && _is_label_char(*str))
			str++;
		is_space(&str);
		if (*str != COMMENT_CHAR && *str != ALT_COMMENT_CHAR && *str != '\0')
			error("symbols after");
		return (0);
	}
	else if ((*str == '-' || _is_number_char(*str)) && *str)
	{
		*str == '-' && (!*(str + 1) || *(str + 1) == '0') ? error("error symbols afetr -") : 0;
		str += 1;
		while (*str && _is_number_char(*str))
			str++;
		is_space(&str);
		if (*str != COMMENT_CHAR && *str != ALT_COMMENT_CHAR && *str != '\0')
			error("symbols after");
	}
	else
		error("poka error");
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