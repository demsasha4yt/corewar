#include "asm.h"

int	save_command(t_asm *asm_ms, char *str, t_token *current)
{
	int i;

	i = 0;
	while(i < 16)
	{
		if(ft_strncmp(str,op_tab[i].name, ft_strlen(op_tab[i].name)) == 0)
		{
			current->command = op_tab[i].name;
			current->index = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int check_command(t_asm *asm_ms, char *str, t_token *current) //token-туда записывать
{
	unsigned a = 4;
	unsigned b = 2;
	unsigned c = (a | b);
	if(c == a)
		c = 15;
	if (!save_command(asm_ms, str, current))
	{
		perror("command not found");
		exit(1);
	}
	str += ft_strlen(current->command);
	is_space(&str);
	if(op_tab[current->index].args_num == 1)
		asm_ms->current_byte += op_tab[current->index].args_types[0];
	return (0);
}
