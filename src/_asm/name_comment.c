#include "asm.h"

void check_name_comment_name_p2(int i, t_asm *asm_ms)
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
			return ;
		}
		if (!(*str))
			asm_ms->name[i++] = '\n';
		free(str);
	}
}
