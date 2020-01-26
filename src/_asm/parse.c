#include "asm.h"

void parse_p2(t_asm *asm_ms)
{
	char *str;
	char *str1;

	while (get_next_line(asm_ms->fd_r, &str) > 0)
	{
		str1 = str;
		if (is_blank(str1))
			continue;
		is_space(&str1);
		if (check_label(str1, asm_ms))
		{
			// if ((get_next_line(asm_ms->fd_r, &str1) > 0) &&
			// (check_command(str1, asm_ms)))
			// check_command(str1)
		}
		else if (check_command(str1, asm_ms))
		{

		}
		// //check_comment
		// if (check_label(str1, asm_ms))
		// {
		// 	if ((get_next_line(asm_ms->fd_r, &str1) > 0) &&
		// 	(check_command(str1, asm_ms)))
		// 		{
		// 			free(str1);
		// 			continue;
		// 		}
		// 	else
		// 		ft_printf("error\n");
		// 	// free(str);
		// 	// continue;
		// }
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
		{
			free(str);
			continue;
		}
		if(asm_ms->name && asm_ms->comment)
			break ;
	}
	parse_p2(asm_ms);
}
