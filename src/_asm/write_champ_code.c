#include "asm.h"

// int char_to_int(char c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (c - '0');
// 	else if (c == 'a')
// 		return (10);
// 	else if (c == 'b')
// 		return (11);
// 	else if (c == 'c')
// 		return (12);
// 	else if (c == 'd')
// 		return (13);
// 	else if (c == 'e')
// 		return (14);
// 	else
// 		return (15);
// }

void write_magic_header(t_asm *asm_ms)
{
	char *char_to_print;
	int i;
	char ch;

	ch = 0;
	i = COREWAR_EXEC_MAGIC;
	write(asm_ms->fd_w, &ch, 1);
	char_to_print = (char *)(&i);
	ft_printf("%d", ft_strlen(char_to_print));
	write(asm_ms->fd_w, char_to_print, 3);
}

void write_null(t_asm *asm_ms)
{
	char c;
	int i;

	c = 0;
	i = -1;
	while (++i < 8)
		write(asm_ms->fd_w, &c, 1);
}

// void write_size(t_asm *asm_ms)
// {
// 	t_fs size;
//
// 	size.i = asm_ms->code_size;
// 	write(asm_ms->fd_w, &(size.i.c1), 1);
// 	write(asm_ms->fd_w, &(size.i.c2), 1);
// 	write(asm_ms->fd_w, &(size.i.c3), 1);
// 	write(asm_ms->fd_w, &(size.i.c4), 1);
// }

// void write_code(t_asm *asm_ms)
// {
// 	t_token *current;
//
// 	current = asm_ms->first;
// 	while (current)
// 	{
// 		write(asm_ms->fd_w, current->code, ft_strlen(current->code));
// 		current = current->next;
// 	}
// }

void write_champ_code(t_asm *asm_ms)
{
	write_magic_header(asm_ms);
	write(asm_ms->fd_w, asm_ms->name, PROG_NAME_LENGTH);
	write_null(asm_ms);
	//write_size(asm_ms);
	write(asm_ms->fd_w, asm_ms->comment, COMMENT_LENGTH);
	write_null(asm_ms);
	//write_code(asm_ms);
	if ((close(asm_ms->fd_w)) == -1)
		asm_error(7);
}
