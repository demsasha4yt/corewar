/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:41:52 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/31 21:53:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	push_in_carries_list(t_cw *cw, t_carry *carry)
{
	if (!cw->carries)
	{
		cw->carries = carry;
		return ;
	}
	carry->next = cw->carries;
	cw->carries->prev = carry;
	cw->carries = carry;
}

t_carry		*push_new_carry(t_cw *cw, int byte, int player)
{
	t_carry		*carry;

	carry = new_carry(cw);
	if (!carry)
		terminate(1, cw);
	carry->id = ++(cw->carries_count);
	carry->position = byte;
	carry->carry = 0;
	carry->live_cycle = 0;
	carry->prev = NULL;
	carry->registers[0] = get_player_in_byte(cw, byte) * -1;
	carry->player = player;
	push_in_carries_list(cw, carry);
	return (carry);
}
