#include "asm.h"

int	is_space(char **str)
{
	if(**str && (**str == ' ' || **str == '\t'))
	{
		while (**str && (**str == ' ' || **str == '\t'))
		{
			(*str)++;
		}
		return (1);
	}
	return (0);
}

int is_blank(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		++i;
	if (!(str[i]) || str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
	{
		free(str);
		return (1);
	}
	return (0);
}

int is_comment(char *str)
{
	if (*str && (*str == COMMENT_CHAR || *str == ALT_COMMENT_CHAR))
		return (1);
	return (0);
}

int count_label(t_asm *asm_ms, char *str, int byte)
{
	t_label *label;

	label = asm_ms->label;
	while (label)
	{
		if (!(ft_strcmp(label->name, str)))
			return (byte - label->byte);
		label = label->next;
	}
	ft_printf("label not found");
	//asm_error();
	return (0);
}
