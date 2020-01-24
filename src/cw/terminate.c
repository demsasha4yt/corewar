/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:24:48 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/24 21:46:11 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		terminate(int code, t_cw *cw)
{
	destroy_cw(cw);
	ft_printf("Error code: %d\n", code);
	exit(code);
}