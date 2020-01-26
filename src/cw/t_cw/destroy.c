/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:24:04 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/26 19:43:16 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_cw(t_cw *cw)
{
	destroy_arena(cw);
	destroy_all_carries(cw);
	destroy_all_plys(cw);
}