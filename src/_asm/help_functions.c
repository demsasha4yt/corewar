#include "asm.h"

int	is_space(char **str)
{
	if(**str == ' ' || **str == '\t')
	{
		while (**str == ' ' || **str == '\t')
		{
			(*str)++;
		}
		return (1);
	}
	return (0);
}

int is_blank(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	if (!(str[i]) || str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
	{
		free(str);
		return (1);
	}
	return (0);
}

int is_comment(char *str)
{
	if (*str && (*str == COMMENT_CHAR || *str == ALT_COMMENT_CHAR))
		return (1);
	return (0);
}

char arg_byte(int arg1, int arg2, int arg3)
{
	int res;

	res = 0;
	if (arg3 == 1)
		res += 4;
	else if (arg3 == 2)
		res += 8;
	else
		res += 12;
	if (arg2 == 1)
		res += 16;
	else if (arg2 == 2)
		res += 32;
	else
		res += 48;
	if (arg1 == 1)
		res += 64;
	else if (arg1 == 2)
		res += 128;
	else
		res += 192;
	return ((char)res);
}

char shell_arg_byte(int type_args)
{
	return (arg_byte(type_args / 100, (type_args / 10) % 10, type_args % 10));
}