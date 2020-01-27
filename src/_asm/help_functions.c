#include "asm.h"

int	is_space(char **str)
{
	if(**str && (**str == ' ' || **str == '\t'))
	{
		while (**str && (**str == ' ' || **str == '\t'))
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
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
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


//arg1 - arg1 type
//1 - T_REG
//2 - T-DIR
//3 - T-IND
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

int count_label(t_asm *asm_ms, char *str, int byte)
{
	t_label *label;

	label = asm_ms->label;
	while (label)
	{
		if (!(ft_strcmp(label->name, str)))
			return (byte - label->byte);
		label = label->next;
	}
	ft_printf("label not found");
	//asm_error();
	return (0);
}
