#include "asm.h"

void parse_p2(t_asm *asm_ms)
{
	char *str;
	char *str1;
	t_token *new;

	while (get_next_line(asm_ms->fd_r, &str) > 0)
	{
		str1 = str;
		if (is_blank(str1))
			continue;
		is_space(&str1);
		if (!(check_label(&str1, asm_ms)))
		{
			new = init_token_p1(asm_ms);
			ft_printf("Проверка на команду после метки\n");
			//check_command(ams_ms, str1, token);
		}
		free(str);
	}
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
			free(str);
		if(asm_ms->name && asm_ms->comment)
			break ;
	}
	parse_p2(asm_ms);
}
