/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_carry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 22:16:55 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/03 20:39:20 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	move_carry(t_carry *carry, t_cw *cw)
{
	(void)cw;
	carry->position = calc_addr(carry->position + carry->step);
}
