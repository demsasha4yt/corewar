/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:33:25 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/03 21:34:59 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	cw_st(t_cw *cw, t_carry *carry)
{
	ft_printf("Do op: \"st\" [CYCLE: %d]\n", cw->cycles);
	(void)carry;
}
