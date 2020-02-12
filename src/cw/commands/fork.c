/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:31:41 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 09:09:04 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_fork(t_cw *cw, t_carry *carry)
{
	int		a;
	
	carry->step += OP_SIZE;
	a = get_argument(cw, carry, 1, true);
	carry_duplicate(cw, carry, a % IDX_MOD);
	if (cw->v & OP_LOG)
		log_fork(carry, a);
}
