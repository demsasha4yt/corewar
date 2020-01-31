/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:07:58 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/31 21:36:10 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

static int	_do_op(t_carry *carry, t_cw *cw)
{
	t_op *op;
	

	(void)op;
	(void)carry;
	(void)cw;
	return (1);
	// TODO: do operation
}

static void	_update_op(t_carry *carry, t_cw *cw)
{
	(void)carry;
	(void)cw;

	// TODO: update op
}

static void	_cycle_carry(t_carry *carry, t_cw *cw)
{
	(void)cw;
	if (carry->cycles_to_exec == 0)
		_update_op(carry, cw);
	if (carry->cycles_to_exec > 0)
		carry->cycles_to_exec -= 1;
	if (carry->cycles_to_exec == 0) 
	{
		if (!_do_op(carry, cw))
			;
	}
}

static void	_cycle(t_cw *cw)
{
	t_carry *carry;
	
	cw->cycles += 1;
	cw->cycles_to_check += 1;
	carry = cw->carries;
	while (carry)
	{
		_cycle_carry(carry, cw);
		carry = carry->next;
	}
}

void	main_cycle(t_cw *cw)
{
	while (cw->carries)
	{
		if (cw->cycles == 3000)
			return ; // DELETE!
		if (cw->cycles == cw->dump_cycles)
		{
			// TODO: print arena (dump mode)
			terminate(0, cw);
		}
		if (cw->cycles == cw->d_cycles)
		{
			// TODO: print arena (d mode)
			terminate(0, cw);
		}
		_cycle(cw);
		if (cw->cycles_to_die <= 0
			|| cw->cycles_to_check == cw->cycles_to_die)
			check(cw);
	}
}
