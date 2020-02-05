/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:31:17 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/05 22:09:39 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_add(t_cw *cw, t_carry *carry)
{
	ft_printf("Do op: \"add\" [CYCLE: %d CARRY: %d]\n", cw->cycles, carry->id);
	int	r1;
	int	r2;
	int	r3;
	int	value;

	carry->step = (OP_SIZE + ARGS_SIZE);
	r1 = arena_get_byte(cw, carry->position, carry->step);
	carry->step += REG_LEN;
	r2 = arena_get_byte(cw, carry->position, carry->step);
	carry->step += REG_LEN;
	value = carry->registers[r1 - 1] + carry->registers[r2 - 1];
	carry->carry = (!value) ? 1 : 0;
	r3 = arena_get_byte(cw, carry->position, carry->step);
	carry->registers[r3 - 1] = value;
	carry->step += REG_LEN;
}
