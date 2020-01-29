#include "asm.h"

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

void write_size(t_asm *asm_ms)
{
	char *size;
	int len;

	size = (char *)(&(asm_ms->current_byte));
	len = ft_strlen(size);
	while (++len <= 4)
		write(asm_ms->fd_w, "\0", 1);
	len = ft_strlen(size);
	write(asm_ms->fd_w, "\0", len);
}

void write_code(t_asm *asm_ms)
{
	t_token *token;

	token = asm_ms->first;
	while (token)
	{
		write(asm_ms->fd_w, token->command, ft_strlen(token->command));
		token = token->next;
	}
}

void write_champ_code(t_asm *asm_ms)
{
	write_magic_header(asm_ms);
	write(asm_ms->fd_w, asm_ms->name, PROG_NAME_LENGTH);
	write_null(asm_ms);
	write_size(asm_ms);
	write(asm_ms->fd_w, asm_ms->comment, COMMENT_LENGTH);
	write_null(asm_ms);
	write_code(asm_ms);
	if ((close(asm_ms->fd_w)) == -1)
		asm_error(7);
}
