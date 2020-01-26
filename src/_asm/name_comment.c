#include "asm.h"

void check_name_p2(int i, t_asm *asm_ms)
{
	int j;
	char *str;

	asm_ms->name[i++] = '\n';
	while (get_next_line(asm_ms->fd_r, &str))
	{
		j = 0;
		while (str[j] != '"' && str[j] && i < PROG_NAME_LENGTH)
			asm_ms->name[i++] = str[j++];
		if (i == PROG_NAME_LENGTH)
			ft_printf("error number symbols (name)\n");
		if (str[j] == '"')
		{
			//проверка на валидность строки после ковычки
			j++;
			while (str[j] == ' ' || str[j] == '\t')//проверка на валидность строки после ковычки \0 # ' ' '\t'
				j++;
			if (str[j] != '#' && str[j] != '\0')
				perror("sym after \" ");
			return;
		}
		if (!(*str))
			asm_ms->name[i++] = '\n';
		free(str);
	}
}

void check_comment_p2(int i, t_asm *asm_ms)
{
	int j;
	char *str;

	asm_ms->comment[i++] = '\n';
	while (get_next_line(asm_ms->fd_r, &str))
	{
		j = 0;
		while (str[j] != '"' && str[j] && i < COMMENT_LENGTH)
			asm_ms->comment[i++] = str[j++];
		if (i == COMMENT_LENGTH)
			ft_printf("error number symbols (comment)\n");
		if (str[j] == '"')
		{
			//проверка на валидность строки после ковычки
			j++;
			while (str[j] == ' ' || str[j] == '\t')//проверка на валидность строки после ковычки \0 # ' ' '\t'
				j++;
			if (str[j] != '#' && str[j] != '\0')
				perror("sym after \" ");
			return;
		}
		if (!(*str))
			asm_ms->comment[i++] = '\n';
		free(str);
	}
}

int check_name_p1(char *str, t_asm *asm_ms, int i)
{
	if (!(asm_ms->name = ft_strnew(PROG_NAME_LENGTH)))
		asm_error(4);
	str += 5;
	is_space(&str);
	if (*str++ == '"')
	{
		while (str[i] != '"' && str[i] && i < PROG_NAME_LENGTH)
		{
			asm_ms->name[i] = str[i];
			i++;
		}
		if (i == PROG_NAME_LENGTH)
			ft_printf("error number symbols (name)\n");
		if (str[i] == '"')
		{
			i++;
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i] != '\0')
				perror("sym after \" ");
		}
		else
			check_name_p2(i, asm_ms);
	}
	else
	{
		ft_printf("error symbols\n");
		exit(0);
	}
	return (1);
}

int check_comment_p1(char *str, t_asm *asm_ms, int i)
{
	if (!(asm_ms->comment = ft_strnew(COMMENT_LENGTH)))
		asm_error(4);
	str += 8;
	is_space(&str);
	if (*str++ == '"')
	{
		while (str[i] != '"' && str[i] && i < COMMENT_LENGTH)
		{
			asm_ms->comment[i] = str[i];
			i++;
		}
		if (i == COMMENT_LENGTH)
			ft_printf("error number symbols (comment)\n");
		if (str[i] == '"')
		{
			i++;
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				i++;
			if (str[i] && str[i] != '#' && str[i] != '\0')
				perror("sym after \" ");
		}
		else
			check_comment_p2(i, asm_ms);
	}
	else
	{
		ft_printf("error symbols\n");
		exit(0);
	}
	return (1);
}

int	check_name_comment(char *str1, t_asm *asm_ms)
{
	char *str;

	str = str1;
	if (*str)
	{
		if (*str == COMMENT_CHAR || *str == ALT_COMMENT_CHAR)
			return (1);
		if (ft_strncmp(str, NAME_CMD_STRING, 5) == 0 && asm_ms->name == NULL)
			check_name_p1(str, asm_ms, 0);
		else if (ft_strncmp(str, NAME_CMD_STRING, 5) == 0 && asm_ms->name != NULL)
			ft_printf("second name\n");
		else if (ft_strncmp(str, COMMENT_CMD_STRING, 8) == 0
			&& asm_ms->comment == NULL)
			check_comment_p1(str, asm_ms, 0);
		else if (ft_strncmp(str, COMMENT_CMD_STRING, 8) == 0
			&& asm_ms->comment != NULL)
			ft_printf("second comment\n");
		else if (!asm_ms->comment || !asm_ms->name)
			ft_printf("command/label before name/comment\n");
	}
	return (1);
}
