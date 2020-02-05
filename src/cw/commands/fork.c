/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:31:41 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/05 21:53:32 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_fork(t_cw *cw, t_carry *carry)
{
	ft_printf("Do op: \"fork\" [CYCLE: %d CARRY: %d]\n", cw->cycles, carry->id);
	(void)cw;
	(void)carry;
}
