#include "asm.h"

int	check_and_save_command(t_asm *asm_ms, char *str, t_token *current)
{
	int i;

	i = 0;
	while(i < 16)
	{
		if(ft_strncmp(str,op_tab[i].name, ft_strlen(op_tab[i].name)) == 0)
		{
			if(str[0] == 'l' && str[1] == 'd' && str[2] == 'i' && i == 1)
			{
				i++;
				continue ;
			}
			else if(str[0] == 's' && str[1] == 't' && str[2] == 'i' && i == 2)
			{
				i++;
				continue ;
			}
			else if(str[0] == 'l' && str[1] == 'l' && str[2] == 'd' && str[3] == 'i' && i == 12)
			{
				i++;
				continue ;
			}
			current->name = op_tab[i].name;
			current->arg_numbers = op_tab[i].args_num;
			current->code_operation = op_tab[i].code;
			current->index = i;
			current->type_args = current->index == 15 ? 100 : 0; /// вместо 0 - 200??
			return (1);
		}
		i++;
	}
	return (0);
}

void check_valid_commands(t_asm *asm_ms, char *str, t_token *current)
{
	if(ft_strcmp(current->name, "live") == 0 || ft_strcmp(current->name, "fork") == 0 || ft_strcmp(current->name, "lfork") == 0 || ft_strcmp(current->name, "zjmp") == 0 || ft_strcmp(current->name, "aff") == 0)
		_one_argument(asm_ms, str, current);
	else
		_two_three_arguments(asm_ms, str, current);
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
