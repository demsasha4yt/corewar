/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:32:07 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/05 21:00:55 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "corewar.h"
 #include "cw_ops.h"

void	cw_ld(t_cw *cw, t_carry *carry)
{
	ft_printf("Do op: \"ld\" [CYCLE: %d CARRY: %d]\n", cw->cycles, carry->id);
	
	int	value;
	int	r;

	carry->step += (OP_SIZE + ARGS_SIZE);
	value = get_argument(cw, carry, 1, 1);
	carry->carry = (!value) ? 1 : 0;
	r = arena_get_byte(cw, carry->position, carry->step);
	ft_printf("%d %d\n", value, r);
	carry->registers[r - 1] = value;
	carry->step += REG_LEN;
}
