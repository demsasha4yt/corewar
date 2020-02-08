#include "asm.h"

int init_label(char **str, t_label *label, t_asm *asm_ms, int i)
{
	t_token *new;

	new = NULL;
	label->next = NULL;
	label->byte = asm_ms->current_byte;
	if (!(label->name = ft_strsub(*str, 0, i)))
		asm_error(4, -1);
	*str += i + 1;
	is_space(str);
	if (!(is_comment(*str)) && (**str))
	{
		new = init_token_p1(asm_ms);
		check_command(asm_ms, *str, new);
	}
	return (1);
}

void init_token_p2(t_token *token)
{
	token->next = 0;
	token->arg1 = 0;
	token->arg2 = 0;
	token->arg3 = 0;
	token->output = 0;
	token->name = 0;
}

t_token *init_token_p1(t_asm *asm_ms)
{
	t_token *temp;

	temp = asm_ms->first;
	if (!(asm_ms->first))
	{
		if (!(asm_ms->first = (t_token *)(ft_memalloc(sizeof(t_token)))))
			asm_error(4, -1);
		temp = asm_ms->first;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		if (!(temp->next = (t_token *)(ft_memalloc(sizeof(t_token)))))
			asm_error(4, -1);
		temp = temp->next;
	}
	temp->current_line = asm_ms->current_line;
	init_token_p2(temp);
	return (temp);
}

void init_asm_ms(t_asm *asm_ms)
{
	ft_memset(asm_ms, 0, sizeof(t_asm));
	asm_ms->fd_r = -1;
	asm_ms->fd_w = -1;
	asm_ms->first = 0;
	// if (!(asm_ms->comment = ft_strnew(COMMENT_LENGTH)))
	// 	asm_error(4);
}
