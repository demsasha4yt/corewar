#include "asm.h"

int	check_and_save_command(t_asm *asm_ms, char *str, t_token *current)
{
	int i;

	i = 0;
	while(i < 16)
	{
		if(ft_strncmp(str,op_tab[i].name, ft_strlen(op_tab[i].name)) == 0)
		{
			current->name = op_tab[i].name;
			current->index = i;
			return (1);
		}
		i++;
	}
	return (0);
}

//int arg_types(t_asm *asm_ms, char *str, t_token *current)
//{
//	if(op_tab[current->index].args_num == 1)
//	{
//		current->arg1 = op_tab[current->index].args_types[0] &
//	}
//	else if(op_tab[current->index].args_num == 2)
//	{
//
//	}
//	else if(op_tab[current->index].args_num == 3)
//	{
//
//	}
//}

void check_valid_commands(t_asm *asm_ms, char *str, t_token *current)
{
	if(ft_strcmp(current->name, "live") == 0)
		_live_check(str);
	else if(ft_strcmp(current->name, "ld") == 0)
		_ld_check(asm_ms, str, current);
}

int check_command(t_asm *asm_ms, char *str, t_token *current) //token-туда записывать
{
	if (!check_and_save_command(asm_ms, str, current))
	{
		perror("command not found");
		exit(1);
	}
	str += ft_strlen(current->name);
	is_space(&str);
	//arg_types(asm_ms, str, current);
	check_valid_commands(asm_ms, str, current);
	return (0);
}
