/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:30:35 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/10 18:18:17 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_error_p4(int er_nu, int line, t_asm *asm_ms)
{
	if (er_nu == 23)
		ft_printf("%s:%d \x1B[31mSecond declaration of name\n\033[0m",
				asm_ms->error_name, line);
	else if (er_nu == 24)
		ft_printf("%s:%d \x1B[31mSecond declaration of comment\n\033[0m",
				asm_ms->error_name, line);
	else if (er_nu == 26)
	{
		ft_printf("%s:%d \x1B[31mCommand before name/comment declaration.",
			asm_ms->error_name, line);
		ft_printf("\n\033[0m");
	}
}

void	asm_error_p3(int er_nu, int line, t_asm *asm_ms)
{
	if (er_nu == 18)
		ft_printf("s:%d \x1B[31mBad symbols after name declaration\n\033[0m",
				asm_ms->error_name, line);
	else if (er_nu == 19)
		ft_printf("%s:%d \x1B[31mBad comment length\n\033[0m",
				asm_ms->error_name, line);
	else if (er_nu == 20)
		ft_printf("%s:%d \x1B[31mBad symbol after comment declaration\n\033[0m",
				asm_ms->error_name, line);
	else if (er_nu == 21)
	{
		ft_printf("%s:%d \x1B[31mNo quotation mark met after name declaration",
				asm_ms->error_name, line);
		ft_printf("\n\033[0m");
	}
	else if (er_nu == 22)
	{
		ft_printf("%s:%d \x1B[31mNo quotation mark met after comment ",
				asm_ms->error_name, line);
		ft_printf("declaration\n\033[0m");
	}
	asm_error_p4(er_nu, line, asm_ms);
	exit(er_nu);
}

void	asm_error_p2(int er_nu, int line, t_asm *asm_ms)
{
	if (er_nu == 10)
		ft_printf("%s:%d \x1B[31mInvalid type of second argument\n\033[0m",
				asm_ms->error_name, line);
	else if (er_nu == 11)
		ft_printf("%s:%d \x1B[31mInvalid type of third argument\n\033[0m",
				asm_ms->error_name, line);
	else if (er_nu == 12)
		ft_printf("%s:%d \x1B[31mWrong arguments number\n\033[0m",
				asm_ms->error_name, line);
	else if (er_nu == 13)
		ft_printf("%s:%d \x1B[31mWrong label name\n\033[0m",
				asm_ms->error_name, line);
	else if (er_nu == 14)
		ft_printf("%s:%d \x1B[31mBad instruction in first argument\n\033[0m",
				asm_ms->error_name, line);
	else if (er_nu == 15)
		ft_printf("%s:%d \x1B[31mBad instruction in second argument\n\033[0m",
				asm_ms->error_name, line);
	else if (er_nu == 16)
		ft_printf("%s:%d \x1B[31mBad instruction in third argument\n\033[0m",
				asm_ms->error_name, line);
	else if (er_nu == 17)
		ft_printf("%s:%d\x1B[31mBad name length\n\033[0m",
				asm_ms->error_name, line);
	asm_error_p3(er_nu, line, asm_ms);
}

int		is_blank(char *str)
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
