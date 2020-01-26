#include "asm.h"

int	is_space(char **str)
{
	if(**str == ' ' || **str == '\t')
	{
		while (**str == ' ' || **str == '\t')
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
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	if (!(str[i]) || str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR);
	{
		free(str);
		return (1);
	}
	()
	return (0);
}

int is_comment(char *str)
{
	if (*str && (*str == COMMENT_CHAR || *str == ALT_COMMENT_CHAR))
		return (1);
	return (0);
}
