/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:42:58 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/05 22:03:03 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_and(t_cw *cw, t_carry *carry)
{
	ft_printf("Do op: \"and\" [CYCLE: %d CARRY: %d]\n", cw->cycles, carry->id);
	int	val1;
	int	val2;
	int	res;
	int	r;

	carry->step += OP_SIZE + ARGS_SIZE;
	val1 = get_argument(cw, carry, 1, true);
	val2 = get_argument(cw, carry, 2, true);
	res = val1 & val2;
	carry->carry = (!res) ? 1 : 0;
	r = arena_get_byte(cw, carry->position, carry->step);
	carry->registers[r - 1] = res;
	carry->step += REG_LEN;
}
