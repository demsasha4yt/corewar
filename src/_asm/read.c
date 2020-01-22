#include "asm.h"

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
		temp2 = ft_strjoin(file, temp1);
		if (file)
			free(file);
		file = temp2;
	}
	if (i == -1)
		asm_error(5);
	free(temp1);
	return (file);
}
