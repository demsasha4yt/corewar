#include "asm.h"

//r -reg
//% - DIR
void create_args(t_token *token, t_asm *asm_ms)
{
	int byte;

	byte = 2;
	if (token->type_args / 100 == 1)
		byte += create_reg_arg(token, byte, 1, asm_ms);
	else if (token->type_args / 100 == 2)
		byte += create_dir_arg(token, byte, 1, asm_ms);
	else if (token->type_args / 100 == 3)
		byte += create_ind_arg(token, byte, 1, asm_ms);
	if ((token->type_args / 10) % 10 == 1)
		byte += create_reg_arg(token, byte, 2, asm_ms);
	else if ((token->type_args / 10) % 10 == 2)
		byte += create_dir_arg(token, byte, 2, asm_ms);
	else if ((token->type_args / 10) % 10 == 3)
		byte += create_ind_arg(token, byte, 2, asm_ms);
	if (token->type_args % 10 == 1)
		byte += create_reg_arg(token, byte, 3, asm_ms);
	else if (token->type_args % 10 == 2)
		byte += create_reg_arg(token, byte, 3, asm_ms);
	else if (token->type_args % 10 == 3)
		byte += create_reg_arg(token, byte, 3, asm_ms);
}
