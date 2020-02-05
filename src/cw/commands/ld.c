/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:32:07 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/05 22:09:33 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "corewar.h"
 #include "cw_ops.h"

void	cw_ld(t_cw *cw, t_carry *carry)
{
	ft_printf("Do op: \"ld\" [CYCLE: %d CARRY: %d]\n", cw->cycles, carry->id);
	
	int	val;
	int	r;

	carry->step += (OP_SIZE + ARGS_SIZE);
	val = get_argument(cw, carry, 1, 1);
	carry->carry = (!val) ? 1 : 0;
	r = arena_get_byte(cw, carry->position, carry->step);
	ft_printf("%d %d\n", val, r);
	carry->registers[r - 1] = val;
	carry->step += REG_LEN;
}
