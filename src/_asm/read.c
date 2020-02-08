#include "asm.h"

int check_last_row(char *file)
{
	int i;

	i = ft_strlen(file) - 1;
	while (file[i] != '\n')
		--i;
	++i;
	while (file[i] && (file[i] == ' ' || file[i] == '\t'))
		++i;
	if (file[i] && file[i] != COMMENT_CHAR && file[i] != ALT_COMMENT_CHAR)
		return (0);
	return (1);
}

char *asm_read_cycle(t_asm *asm_ms)
{
	char *file;
	char *temp1;
	char *temp2;
	int i;

	temp1 = ft_strnew(10);
	file = 0;
	temp2 = 0;
	i = -1;
	while ((i = read(asm_ms->fd_r, temp1, 9)) > 0)
	{
		temp1[i] = '\0';
		if (!(temp2 = ft_strjoin(file, temp1)))
			asm_error(4, -1, asm_ms);
		if (file)
			free(file);
		file = temp2;
	}
	if (i == -1)
		asm_error(5, -1, asm_ms);
	free(temp1);
	if (!check_last_row(file))
		asm_error(6, -1, asm_ms);
	return (file);
}
