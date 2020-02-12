/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:24:48 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 07:10:04 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		terminate(int code, t_cw *cw)
{
	destroy_cw(cw);
	if (code != 0) {
		write(2, "Error\n", 6);
		// ft_printf("Error code: %d\n", code);
	}
	exit(code);
}
