#include "asm.h"

int	check_and_save_command(char *str, t_token *current)
{
	int i;

	i = 0;
	while(i < 16)
	{
		if(ft_strncmp(str, g_op_tab[i].name, ft_strlen(g_op_tab[i].name)) == 0)
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
			current->name = g_op_tab[i].name;
			current->arg_numbers = g_op_tab[i].args_num;
			current->code_operation = g_op_tab[i].code;
			current->index = i;
			current->type_args = current->index == 15 ? 100 : 0;
			return (1);
		}
		i++;
	}
	return (0);
}

void check_valid_commands(t_asm *asm_ms, char *str, t_token *current)
{
	if(current->code_operation == 1 || current->code_operation == 9 ||
	current->code_operation == 12 || current->code_operation == 16 ||
	current->code_operation == 16)
		one_argument(asm_ms, str, current);
	else
		two_three_arguments(asm_ms, str, current);
}

int check_command(t_asm *asm_ms, char *str, t_token *current) //token-туда записывать
{
	if (!check_and_save_command(str, current))
        asm_error(8, current->current_line);
	str += ft_strlen(current->name);
	is_space(&str);
	check_valid_commands(asm_ms, str, current);
	return (0);
}