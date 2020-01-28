#include "asm.h"

int create_dir_arg_p2(t_token *token, int byte, char *to_parse, int *current_byte)
{
	int to_add;
	int i;

	i = 0;
	if (to_parse[i++] != DIRECT_CHAR)
		ft_printf("NO DIRECT_CHAR\n");
	if (to_parse[i] == LABEL_CHAR)
		to_add = count_label(asm_ms, &(to_parse[i + 1]), current_byte);
	else
		to_add = ft_atoi_asm_ed(&(to_parse[i + 1]);
	return (i);
}

void create_dir_arg(t_token *token, int byte, int arg_nu, t_asm *asm_ms)
{
	char *to_parse;
	int to_add;

	if (arg_nu == 1)
		to_parse = token->arg1;
	else if (arg_nu == 2)
		to_parse = token->arg2;
	else
		to_parse = token->arg3;
	if (arg_nu == 1)
	{
		*current_byte += 1;
		if (*(token->command) != (char)1 && *(token->command) != (char)9
		&& *(token->command) != (char)12 && *(token->command) != (char)15)
		*current_byte += 1;
	}
	to_add = (short)(create_dir_arg_p2(byte, to_parse, asm_ms));
	if ((*(token->command) >= (char)9 && *(token->command) <= (char)12)
	|| ((*(token->command) >= (char)14 && *(token->command) <= (char)15)))
		return(add(to_add, byte, 2);
	else
		return(add(to_add, byte, 4);
}
