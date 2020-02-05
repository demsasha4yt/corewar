/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:31:30 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/05 18:52:20 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw_ops.h"

void	cw_aff(t_cw *cw, t_carry *carry)
{
	ft_printf("Do op: \"aff\" [CYCLE: %d CARRY: %d]\n", cw->cycles, carry->id);
	(void)cw;
	(void)carry;
}
