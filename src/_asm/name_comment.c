#include "asm.h"

void check_name_comment_name_p1(int i, t_asm *asm_ms)
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
			i++;
while (str[i] == ' ' || str[i] == '\t')//проверка на валидность строки после ковычки \0 # ' ' '\t'
i++;
if(str[i] != '#' && str[i] != '\0')
perror("sym after \"");
			return ;
		}
		if (!(*str))
			asm_ms->name[i++] = '\n';
		free(str);
	}
}

void check_name_comment_name_p2(int i, t_asm *asm_ms)
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
			i++;
while (str[i] == ' ' || str[i] == '\t')//проверка на валидность строки после ковычки \0 # ' ' '\t'
i++;
if(str[i] != '#' && str[i] != '\0')
perror("sym after \"");
			return ;
		}
		if (!(*str))
			asm_ms->comment[i++] = '\n';
		free(str);
	}
}
