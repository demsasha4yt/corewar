#include "asm.h"

int check_label_name(char *str)
{
	//
	str = 0;
	return (0);
}

int check_label(char *str, t_asm *asm_ms)
{
	int i;
	t_token *new;
	//

	i = 0;
	new = 0;
		asm_ms = 0;
	while (str[i]) //&& is_labelChar(str[i]))
		i++;
	if (check_label_name(str))
		return (1);
	return (0);
}
