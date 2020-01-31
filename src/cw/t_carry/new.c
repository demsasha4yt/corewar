/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:15:34 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/31 19:07:16 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	initialize_new_registers(t_carry *carry)
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		carry->registers[i] = 0;
}

t_carry		*new_carry(t_cw *cw)
{
	t_carry *carry;

	carry = (t_carry*)ft_memalloc(sizeof(t_carry));
	if (!carry)
		terminate(1, cw);
	carry->id = -1;
	carry->flag = -1;
	carry->live_cycle = -1;
	carry->cycles_left = -1;
	carry->position = -1;
	carry->next = NULL;
	carry->prev = NULL;
	carry->player = -1;
	carry->carry = -1;
	initialize_new_registers(carry);
	return carry;
}
