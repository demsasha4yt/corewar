#include "asm.h"

char	*is_space(char *str)
{
	while(*str == ' ' || *str == '\t')
	{
		str++;
	}
	return (str);
}

void parse_p1(char *file, t_asm *asm_ms)
{
	int i;
	char *str;

	i = 0;
	str = ft_strstr(file, "\n.name");
	if(!str)
		ft_printf("characters before the name\n");
	else
	{
		str += 6;
		str = is_space(str);
		if(*str++ == '"')
		{
			while(str[i] != '"')
			{
				asm_ms->name[i] = str[i];
				i++;
			}
			str += i;
		}
		else
			ft_printf("characters before name\n");
	}
}
