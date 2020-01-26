#include "asm.h"

int init_label(char **str, t_label *label, t_asm *asm_ms, int i)
{
	t_token *new;

	new = NULL;
	label->next = NULL;
	label->byte = asm_ms->current_byte;
	label->name = ft_strsub(*str, 0, i);
	str += i + 1;
	is_space(str);
	if (!(is_comment(*str)) && (*str))
	{
		new = init_token_p1(asm_ms);
		ft_printf("Проверка на команду\n");
		//check_command(asm_ms, str, token);
	}
	return (1);
}

t_token *init_token_p2(t_token *temp)
{
	temp->arg1 = 0;
	temp->arg2 = 0;
	temp->arg3 = 0;
	temp->arg_nu = 0;
	temp->size1 = 0;
	temp->size2 = 0;
	temp->size3 = 0;
	return (temp);
}

t_token *init_token_p1(t_asm *asm_ms)
{
	t_token *temp;

	temp = asm_ms->first;
	if (!(asm_ms->first))
	{
		if (!(asm_ms->first = (t_token *)(malloc(sizeof(t_token)))))
			asm_error(4);
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		if (!(temp->next = (t_token *)(malloc(sizeof(t_token)))))
			asm_error(4);
		temp = temp->next;
	}
	temp->next = 0;
	temp->command = 0;
	return (init_token_p2(temp));
}

void init_asm_ms(t_asm *asm_ms)
{
	asm_ms->fd_r = -1;
	asm_ms->fd_w = -1;
	asm_ms->file_name = NULL;
	asm_ms->name = NULL;
	asm_ms->comment = NULL;
	asm_ms->current_line = 0;
	asm_ms->first = NULL;
	asm_ms->label = NULL;
	asm_ms->current_byte = 0;
	init_op(asm_ms);
	// if (!(asm_ms->comment = ft_strnew(COMMENT_LENGTH)))
	// 	asm_error(4);
}
