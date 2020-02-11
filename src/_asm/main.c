/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:55:04 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/12 00:08:42 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "errors.h"

void	asm_error(int er_nu, int line, t_asm *asm_ms)
{
	if (er_nu == 0)
		ft_printf("x1B[31m%s\n\033[0m", ERR_ARG);
	else if (er_nu == 1)
		ft_printf("\x1B[31m%s\n\033[0m", ERR_FILE_EXT);
	else if (er_nu == 2)
		ft_printf("\x1B[31m%s\n\033[0m", ERR_OPEN);
	else if (er_nu == 3)
		ft_printf("\x1B[31m%s\n\033[0m", ERR_CREATE);
	else if (er_nu == 4)
		ft_printf("\x1B[31m%s\n\033[0m", ERR_MALLOC);
	else if (er_nu == 5)
		ft_printf("\x1B[31m%s\n\033[0m", ERR_READ);
	else if (er_nu == 6)
		ft_printf("%s \x1B[31m%s\n\033[0m",asm_ms->file_name_s, ERR_EOF);
	else if (er_nu == 7)
		ft_printf("\x1B[31m%s\n\033[0m", ERR_CLOSE);
	else if (er_nu == 8)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_COMMAND);
	else if (er_nu == 9)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_TYPE_FIRST_ARG);
	asm_error_p2(er_nu, line, asm_ms);
}

int		asm_create_file(char *argv, t_asm *asm_ms)
{
	int		fd;
	char	*temp;

	if (!(temp = ft_strsub(argv, 0, ft_strlen(argv) - 2)))
		asm_error(4, -1, asm_ms);
	if (!(asm_ms->file_name_cor = ft_strjoin(temp, ".cor")))
		asm_error(4, -1, asm_ms);
	free(temp);
	fd = open(asm_ms->file_name_cor, O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
	return (fd);
}

int		asm_check_name(char *argv, t_asm *asm_ms)
{
	int i;

	i = 0;
	asm_ms->file_name_s = argv;
	while (argv[i])
		++i;
	if (argv[i - 1] && argv[i - 1] == 's' && argv[i - 2] && argv[i - 2] == '.')
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_asm	asm_ms;
	char	*file;

	file = NULL;
	init_asm_ms(&asm_ms);
	if (argc != 2)
		asm_error(0, -1, &asm_ms);
	if (!asm_check_name(argv[1], &asm_ms))
		asm_error(1, -1, &asm_ms);
	if ((asm_ms.fd_r = open(argv[1], O_RDONLY)) == -1)
		asm_error(2, -1, &asm_ms);
	file = asm_read_cycle(&asm_ms);
	if ((close(asm_ms.fd_r) == -1))
		asm_error(7, -1, &asm_ms);
	if ((asm_ms.fd_r = open(argv[1], O_RDONLY)) == -1)
		asm_error(2, -1, &asm_ms);
	parse_p1(&asm_ms);
	write_champ_code(&asm_ms);
	exit(0);
}
