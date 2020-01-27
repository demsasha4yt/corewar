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
	else if (er_nu == 6)
		ft_printf("No \\n at the end of the file\n");
	else if (er_nu == 7)
		ft_printf("Can't close the file\n");
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
	asm_ms->name = NULL;
	asm_ms->comment = NULL;
	asm_ms->current_line = 0;
	asm_ms->first = NULL;
	// if (!(asm_ms->comment = ft_strnew(COMMENT_LENGTH)))
	// 	asm_error(4);
}

void					error(char *str)
{
	ft_printf("\x1B[31mError, \033[0m", str);
	ft_printf("\x1B[31m%s\033[0m\n", str);
	exit(-1);
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
	file = asm_read_cycle(&asm_ms);
	if ((close(asm_ms.fd_r) == -1))
		asm_error(7);
	if ((asm_ms.fd_r = open(argv[1], O_RDONLY)) == -1)
		asm_error(2);
	parse_p1(&asm_ms);
	return (0);
}
