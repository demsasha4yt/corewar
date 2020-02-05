/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:33:25 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/05 20:23:07 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_st(t_cw *cw, t_carry *carry)
{
	int r;
	int value;
	int dest;
	// int addr;

	ft_printf("Do op: \"st\" [CYCLE: %d CARRY: %d]\n", cw->cycles, carry->id);
	carry->step = OP_SIZE + ARGS_SIZE;
	r = arena_get_byte(cw, carry->position, carry->step);
	carry->step += REG_LEN;
	value = carry->registers[r - 1];
	if (carry->args_types[1] == T_REG)
	{
		dest = arena_get_byte(cw, carry->position, carry->step);
		carry->registers[dest - 1] = value;
		carry->step += REG_LEN;
	}
	else
	{
		ft_printf("lol\n");
		dest = arena_bytes_to_int(cw->arena->data, carry->position + carry->step,
		 	IND_SIZE);
		int_to_bytecode(cw, carry->position + dest % IDX_MOD, value, DIR_SIZE);
		carry->step += IND_SIZE;
	}
	ft_printf("%d %d %d\n", value, r, dest);
}
