#include "asm.h"

int add(t_token *token, int to_add, int byte, int size)
{
	int len;
	char *char_to_add;

	char_to_add = (char *)(&to_add);
	len = ft_strlen(char_to_add);
	while (++len <= size)
		token->command[byte++] = '\0';
	while (*char_to_add)
	{
		token->command[byte++] = *char_to_add;
		char_to_add++;
	}
	return (size);
}
