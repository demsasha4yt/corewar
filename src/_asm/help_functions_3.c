/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:46:26 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/10 17:59:11 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_name_p1_5(t_asm *asm_ms, int i)
{
	asm_ms->name[i++] = '\n';
	check_name_p2(i, asm_ms);
}

void	check_comment_p1_5(t_asm *asm_ms, int i)
{
	asm_ms->comment[i++] = '\n';
	check_comment_p2(i, asm_ms);
}
