/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:34:00 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/05 21:17:26 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_zjmp(t_cw *cw, t_carry *carry)
{
	int addr;
	
	ft_printf("Do op: \"zjmp\" [CYCLE: %d CARRY: %d]\n", cw->cycles, carry->id);
	carry->step += OP_SIZE;
	addr = get_argument(cw, carry, 1, true);
	if (carry->carry)
	{
		carry->position = calc_addr(carry->position + (addr % IDX_MOD));
		carry->step = 0;
	}
}

