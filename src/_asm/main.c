#include "asm.h"

void asm_error(int er_nu)
{
	if (er_nu == 0)
		ft_printf("Wrong argument number\n");
	else if (er_nu == 1)
		ft_printf("Wrong file extention\n");
	else if (er_nu == 2)
		ft_printf("Can't open file\n");
	else if (er_nu == 3)
		ft_printf("Can't create .cor file\n");
	else if (er_nu == 4)
		ft_printf("Malloc error\n");
	else if (er_nu == 5)
		ft_printf("Read error\n");
	exit(0);
}

int asm_create_file(char *argv, t_asm *asm_ms)
{
	int fd;
	char *temp;

	if (!(temp = ft_strsub(argv, 0, ft_strlen(argv) - 2)))
		asm_error(4);
	if (!(asm_ms->file_name = ft_strjoin(temp, ".cor")))
		asm_error(4);
	free(temp);
	fd = open(asm_ms->file_name, O_WRONLY);
	return (fd);
}

int asm_check_name(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
		++i;
	if (argv[i - 1] && argv[i - 1] == 's' && argv[i - 2] && argv[i - 2] == '.')
		return (1);
	return (0);
}

void init_asm_ms(t_asm *asm_ms)
{
	asm_ms->fd_r = -1;
	asm_ms->fd_w = -1;
	asm_ms->file_name = NULL;
	if (!(asm_ms->name = ft_strnew(PROG_NAME_LENGTH)))
		asm_error(4);
	if (!(asm_ms->comment = ft_strnew(COMMENT_LENGTH)))
		asm_error(4);
}

int main(int argc, char **argv)
{
	t_asm asm_ms;
	char *file = NULL;

	init_asm_ms(&asm_ms);
	if (argc != 2)
		asm_error(0);
	if (!asm_check_name(argv[1]))
		asm_error(1);
	if ((asm_ms.fd_r = open(argv[1], O_RDONLY)) == -1)
		asm_error(2);
	if ((asm_ms.fd_w = asm_create_file(argv[1], &asm_ms)) == -1)
		asm_error(3);
	//file = asm_read_cycle(&asm_ms);
	parse_p1(file, &asm_ms);
	return (0);
}
