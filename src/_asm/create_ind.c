#include "asm.h"

int create_ind_arg_p2(char *to_parse, t_asm *asm_ms)
{
	int to_add;

	if (to_parse[0] == LABEL_CHAR)
		to_add = count_label(asm_ms, &(to_parse[1]), asm_ms->current_byte);
	else
		to_add = ft_atoi(&(to_parse[0]));
	return (to_add);
}

int create_ind_arg(t_token *token, int byte, int arg_nu, t_asm *asm_ms)
{
	char *to_parse;
	int to_add;
	int res;

	if (arg_nu == 1)
		to_parse = token->arg1;
	else if (arg_nu == 2)
		to_parse = token->arg2;
	else
		to_parse = token->arg3;
	if (arg_nu == 1)
		asm_ms->current_byte += 2;
	to_add = create_ind_arg_p2(to_parse, asm_ms);
	res = add(token, to_add, byte, 2);
	asm_ms->current_byte += res;
	return (res);
}
