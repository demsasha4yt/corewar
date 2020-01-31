/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:09:08 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/31 19:22:14 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cycle_read_command(t_carry *carry, t_cw *cw)
{
	ft_printf("%d\n", carry->position);
	ft_printf("%.2x\n", *get_bytes_at_position(cw, carry->position));
}
