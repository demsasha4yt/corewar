/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:24:48 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/26 18:42:15 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		terminate(int code, t_cw *cw)
{
	destroy_cw(cw);
	ft_printf("Error code: %d\n", code);
	exit(code);
}
