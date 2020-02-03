/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_byte_value.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:22:00 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/03 20:26:08 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline int8_t		carry_get_byte(t_cw *cw, t_carry *carry, int step)
{
	return (cw->arena->data[calc_addr(carry->position + step)]);
}
