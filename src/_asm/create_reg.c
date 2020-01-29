#include "asm.h"

int create_reg_arg(t_token *token, int byte, int arg_nu, t_asm *asm_ms)
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
	to_add = ft_atoi(&(to_parse[1]));
	res = add(token, to_add, byte, 1);
	asm_ms->current_byte += res;
	return (res);
}
