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

int is_blank(const char *str)
{
	if(!*str)
		return (1);
	return (0);
}

int	check_name_comment(char *str, t_asm *asm_ms)
{
	int i;

	if (*str)
	{
		if (*str == '#')
			return (1);
		if (ft_strncmp(str, NAME_CMD_STRING, 5) == 0)
		{
			str += 5;
			is_space(&str);
			if(*str++ == '"')
			{
				i = 0;
				while (str[i] != '"')
				{
					asm_ms->name[i] = str[i];
					i++;
				}
				return (1);
			}
			else
			{
				ft_printf("error symbols\n");
				exit(0);
			}

		}
		else if (ft_strncmp(str, COMMENT_CMD_STRING, 8) == 0)
		{
			str += 8;
			is_space(&str);
			if (*str++ == '"')
			{
				i = 0;
				while (str[i] != '"')
				{
					asm_ms->comment[i] = str[i];
					i++;
				}
				return (1);
			}
			else
			{
				ft_printf("error symbols\n");
				exit(0);
			}
		}
		else
		{
			ft_printf("error symbols\n");
			exit(0);
		}
	}
	else
	{
		return (1);
	}
}

void parse_p1(char *file, t_asm *asm_ms)
{
	char *str;

	str = file;

	while (get_next_line(asm_ms->fd_r, &str))
	{
		if (is_blank(str))
			continue ;
		is_space(&str);
		if (check_name_comment(str, asm_ms))
			continue;
	}
}
