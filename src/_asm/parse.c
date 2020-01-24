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
		if (*str == COMMENT_CHAR || *str == ALT_COMMENT_CHAR)
			return (1);
		if (ft_strncmp(str, NAME_CMD_STRING, 5) == 0 && asm_ms->name == NULL)
		{
			if (!(asm_ms->name = ft_strnew(PROG_NAME_LENGTH)))
				asm_error(4);
			str += 5;
			is_space(&str);
			if (*str++ == '"')
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
					//CDE
					//проверка на валидность строки после ковычки
					i++;
					while (str[i] == ' ' || str[i]
						== '\t')//проверка на валидность строки после ковычки \0 # ' ' '\t'
						i++;
					if (str[i] != '#' && str[i] != '\0')
						perror("sym after \" ");
					return (1);
				}
				else
					check_name_comment_name_p1(i, asm_ms);
			}
			else
			{
				ft_printf("error symbols\n");
				exit(0);
			}
		}
		else if (ft_strncmp(str, NAME_CMD_STRING, 5) == 0 && asm_ms->name != NULL)
			ft_printf("second name\n");
		else if (ft_strncmp(str, COMMENT_CMD_STRING, 8) == 0
			&& asm_ms->comment == NULL)
		{
			if (!(asm_ms->comment = ft_strnew(COMMENT_LENGTH)))
				asm_error(4);
			str += 8;
			is_space(&str);
			if (*str++ == '"')
			{
				i = 0;
				while (str[i] != '"' && str[i] && i < COMMENT_LENGTH)
				{
					asm_ms->comment[i] = str[i];
					i++;
				}
				if (i == COMMENT_LENGTH)
					ft_printf("error number symbols (comment)\n");
				if (str[i] == '"')
				{
					//CDE
					//проверка на валидность строки после ковычки
					i++;
					while (str[i] && (str[i] == ' ' || str[i]
						== '\t'))//проверка на валидность строки после ковычки \0 # ' ' '\t'
						i++;
					if (str[i] && str[i] != '#' && str[i] != '\0')
						perror("sym after \" ");
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
		else if (ft_strncmp(str, COMMENT_CMD_STRING, 8) == 0
			&& asm_ms->comment != NULL)
			ft_printf("second comment\n");
		else if (!asm_ms->comment || !asm_ms->name)
			ft_printf("command before name/comment\n");
	}
	else
		return (1);
}

void parse_p1(t_asm *asm_ms)
{
	char *str;
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
		if(asm_ms->name && asm_ms->comment)
			break ;
	}
}
