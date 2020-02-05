/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:33:34 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/05 22:08:24 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_sti(t_cw *cw, t_carry *carry)
{
	ft_printf("Do op: \"sti\" [CYCLE: %d CARRY: %d]\n", cw->cycles, carry->id);
	int	r;
	int	value;
	int	a1;
	int	a2;
	
	carry->step += OP_SIZE + ARGS_SIZE;
	r = arena_get_byte(cw, carry->position, carry->step);
	value = carry->registers[r - 1];
	carry->step += REG_LEN;
	a1 = get_argument(cw, carry, 2, true);
	a2 = get_argument(cw, carry, 3, true);
	int_to_bytecode(cw, (carry->position + ((a1 + a2) % IDX_MOD)),
		 value, DIR_SIZE);
}
