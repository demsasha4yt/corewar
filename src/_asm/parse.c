#include "asm.h"

void parse_p3(t_asm *asm_ms)
{
	t_token *temp;

	temp = asm_ms->first;
	asm_ms->current_byte = 0;
	while (temp)
	{
		if ((token->type_args / 100) != 0)
			create_args(token, 1, asm_ms);
		else if (*(token->command) != (char)16)
			((create_dir_arg(token, 1, 1, asm_ms)))
		// else
		// 	//create_reg_arg
		temp = temp->next;
	}
}

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
	//parse_p3(t_asm *asm);
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
