/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:33:25 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/05 22:08:45 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_st(t_cw *cw, t_carry *carry)
{
	int r;
	int value;
	int a;

	ft_printf("Do op: \"st\" [CYCLE: %d CARRY: %d]\n", cw->cycles, carry->id);
	carry->step = OP_SIZE + ARGS_SIZE;
	r = arena_get_byte(cw, carry->position, carry->step);
	carry->step += REG_LEN;
	value = carry->registers[r - 1];
	if (carry->args_types[1] == T_REG)
	{
		a = arena_get_byte(cw, carry->position, carry->step);
		carry->registers[a - 1] = value;
		carry->step += REG_LEN;
	}
	else
	{
		a = arena_bytes_to_int(cw->arena->data, carry->position + carry->step,
		 	IND_SIZE);
		int_to_bytecode(cw, carry->position + a % IDX_MOD, value, DIR_SIZE);
		carry->step += IND_SIZE;
	}
}
