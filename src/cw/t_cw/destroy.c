/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:24:04 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/24 20:47:38 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_cw(t_cw *cw)
{
	destroy_arena(cw);
	destroy_all_carries(cw);
	destroy_all_plys(cw);
}