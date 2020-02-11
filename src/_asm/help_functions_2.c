/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:30:35 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/11 23:42:08 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "errors.h"

void	asm_error_p4(int er_nu, int line, t_asm *asm_ms)
{
	if (er_nu == 23)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_DOUBLE_NAME);
	else if (er_nu == 24)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_DOUBLE_COMMENT);
	else if (er_nu == 25)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_SYM_BEFORE);
	else if (er_nu == 26)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_QUOT_OR_CODE);
	exit(er_nu);
}

void	asm_error_p3(int er_nu, int line, t_asm *asm_ms)
{
	if (er_nu == 18)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_BAD_SYM_NAME);
	else if (er_nu == 19)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_COMMENT_LENGTH);
	else if (er_nu == 20)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_BAD_SYM_COMMENT);
	else if (er_nu == 21)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_QUOT_NAME);
	else if (er_nu == 22)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_QUOT_COMMENT);
	asm_error_p4(er_nu, line, asm_ms);
}

void	asm_error_p2(int er_nu, int line, t_asm *asm_ms)
{
	if (er_nu == 10)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_TYPE_SECOND_ARG);
	else if (er_nu == 11)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_TYPE_THIRD_ARG);
	else if (er_nu == 12)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_ARG_NUMBER);
	else if (er_nu == 13)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_LABEL_NAME);
	else if (er_nu == 14)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_INSTR_FIRST_ARG);
	else if (er_nu == 15)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_INSTR_SECOND_ARG);
	else if (er_nu == 16)
		ft_printf("%s:%d \x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_INSTR_THIRD_ARG);
	else if (er_nu == 17)
		ft_printf("%s:%d\x1B[31m%s\n\033[0m",
			asm_ms->file_name_s, line, ERR_NAME_LENGTH);
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
