#include "asm.h"

int check_label_name(char *str)
{

}

int check_label(char *str, t_asm *asm_ms)
{
	int i;
	t_token

	i = 0;
	while (str[i] && is_labelChar(str[i]))
		i++;
	if (check_label_name())
		return (1);
	return (0);
}
