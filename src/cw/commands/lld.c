/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:33:01 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/05 18:52:10 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_lld(t_cw *cw, t_carry *carry)
{
	ft_printf("Do op: \"lld\" [CYCLE: %d CARRY: %d]\n", cw->cycles, carry->id);
	(void)cw;
	(void)carry;
}
