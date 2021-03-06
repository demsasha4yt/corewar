/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_lld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:37:35 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 08:44:36 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	log_lld(int carry, int value, int r)
{
	ft_printf("P %4d | lld %d r%d\n", carry, value, r);
}
