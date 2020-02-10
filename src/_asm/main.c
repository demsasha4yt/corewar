#include "asm.h"

void asm_error(int er_nu, int line, t_asm *asm_ms)
{
    if (er_nu == 0)
        ft_printf("\x1B[31mWrong argument number\n\033[0m");
    else if (er_nu == 1)
        ft_printf("\x1B[31mWrong file extention\n\033[0m");
    else if (er_nu == 2)
        ft_printf("\x1B[31mCan't open file\n\033[0m");
    else if (er_nu == 3)
        ft_printf("\x1B[31mCan't create .cor file\n\033[0m");
    else if (er_nu == 4)
        ft_printf("\x1B[31mMalloc error\n\033[0m");
    else if (er_nu == 5)
        ft_printf("\x1B[31mRead error\n\033[0m");
    else if (er_nu == 6)
        ft_printf("\x1B[31mNo \\n at the end of the file\n\033[0m");
    else if (er_nu == 7)
        ft_printf("\x1B[31mCan't close the file\n\033[0m");
    else if (er_nu == 8)
        ft_printf("%s:%d \x1B[31mInvalid command\n\033[0m",asm_ms->error_name, line);
    else if (er_nu == 9)
        ft_printf("%s:%d \x1B[31mInvalid type of first argument\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 10)
        ft_printf("%s:%d \x1B[31mInvalid type of second argument\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 11)
        ft_printf("%s:%d \x1B[31mInvalid type of third argument\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 12)
        ft_printf("%s:%d \x1B[31mWrong arguments number\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 13)
        ft_printf("%s:%d \x1B[31mWrong label name\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 14)
        ft_printf("%s:%d \x1B[31mInvalid instruction in first argument\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 15)
        ft_printf("%s:%d \x1B[31mInvalid instruction in second argument\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 16)
        ft_printf("%s:%d \x1B[31mInvalid instruction in third argument\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 17)
        ft_printf("%s:%d\x1B[31mBad name length\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 18)
        ft_printf("s:%d \x1B[31mBad symbols after name declaration\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 19)
        ft_printf("%s:%d \x1B[31mBad comment length\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 20)
        ft_printf("%s:%d \x1B[31mBad symbols after comment declaration\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 21)
        ft_printf("%s:%d \x1B[31mBad character. No quotation mark met after name declaration\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 22)
        ft_printf("%s:%d \x1B[31mBad character. No quotation mark met after comment declaration\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 23)
        ft_printf("%s:%d \x1B[31mSecond declaration of name\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 24)
        ft_printf("%s:%d \x1B[31mSecond declaration of comment\n\033[0m", asm_ms->error_name, line);
    else if (er_nu == 26)
        ft_printf("%s:%d \x1B[31mCommand before name/comment declaration.\n\033[0m", asm_ms->error_name, line);
    exit(er_nu);
}

int asm_create_file(char *argv, t_asm *asm_ms)
{
	int fd;
	char *temp;

	if (!(temp = ft_strsub(argv, 0, ft_strlen(argv) - 2)))
		asm_error(4, -1, asm_ms);
	if (!(asm_ms->file_name = ft_strjoin(temp, ".cor")))
		asm_error(4, -1, asm_ms);
	free(temp);
	fd = open(asm_ms->file_name, O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
	return (fd);
}

int asm_check_name(char *argv, t_asm *asm_ms)
{
	int i;

	i = 0;
	asm_ms->error_name = argv;
	while (argv[i])
		++i;
	if (argv[i - 1] && argv[i - 1] == 's' && argv[i - 2] && argv[i - 2] == '.')
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	t_asm asm_ms;
	char *file;

	file = NULL;
	init_asm_ms(&asm_ms);
	if (argc != 2)
		asm_error(0, -1, &asm_ms);
	if (!asm_check_name(argv[1], &asm_ms))
		asm_error(1, -1, &asm_ms);
	if ((asm_ms.fd_r = open(argv[1], O_RDONLY)) == -1)
		asm_error(2, -1, &asm_ms);
	if ((asm_ms.fd_w = asm_create_file(argv[1], &asm_ms)) == -1)
		asm_error(3, -1, &asm_ms);
	file = asm_read_cycle(&asm_ms);
	if ((close(asm_ms.fd_r) == -1))
		asm_error(7, -1, &asm_ms);
	if ((asm_ms.fd_r = open(argv[1], O_RDONLY)) == -1)
		asm_error(2, -1, &asm_ms);
	parse_p1(&asm_ms);
	write_champ_code(&asm_ms);
	exit(0);
	//free_all(&asm_ms);
//	return (0);
}
