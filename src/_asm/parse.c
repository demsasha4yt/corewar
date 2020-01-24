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
	if(!*str)
	{
		free(str);
		return (1);
	}
	return (0);
}

int	check_name_comment(char *str1, t_asm *asm_ms)
{
	int i;
	char *str;

	str = str1;
	if (*str)
	{
		//;
		if (*str == COMMENT_CHAR	|| *str == ALT_COMMENT_CHAR)
			return (1);
		if (ft_strncmp(str, NAME_CMD_STRING, 5) == 0 && asm_ms->name == NULL)
		{
			if (!(asm_ms->name = ft_strnew(PROG_NAME_LENGTH)))
				asm_error(4);
			str += 5;
			is_space(&str);
			if(*str++ == '"')
			{
				i = 0;
				while (str[i] != '"' && str[i] && i < PROG_NAME_LENGTH)
				{
					asm_ms->name[i] = str[i];
					i++;
				}
				if (i == PROG_NAME_LENGTH)
					ft_printf("error number symbols (name)\n");
				if (str[i] == '"')
				{
					//проверка на валидность строки после ковычки
					return (1);
				}
				else
					check_name_comment_name_p2(i, asm_ms);
			}
			else
			{
				ft_printf("error symbols\n");
				exit(0);
			}

		}
		else if (ft_strncmp(str, NAME_CMD_STRING, 5) == 0 && asm_ms->name != NULL)
			ft_printf("second name\n");
//		else if (ft_strncmp(str, COMMENT_CMD_STRING, 8) == 0)
//		{
//			str += 8;
//			is_space(&str);
//			if (*str++ == '"')
//			{
//				i = 0;
//				while (str[i] != '"')
//				{
//					asm_ms->comment[i] = str[i];
//					i++;
//				}
//				return (1);
//			}
//			else
//			{
//				ft_printf("error symbols\n");
//				exit(0);
//			}
//		}
//		else
//		{
//			ft_printf("error symbols\n");
//			exit(0);
//		}
	}
	else
	{
		return (1);
	}
}

void parse_p1(t_asm *asm_ms)
{
	char *str;
	int i;
	char *str1;


	while (get_next_line(asm_ms->fd_r, &str) > 0)
	{
		str1 = str;
		if (is_blank(str1))
			continue;
		is_space(&str1);
		if (check_name_comment(str1, asm_ms))
		{
			free(str);
			continue;
		}
	}
}
