/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:24:04 by bharrold          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/01/22 20:03:26 by bharrold         ###   ########.fr       */
=======
/*   Updated: 2020/01/24 20:47:38 by bharrold         ###   ########.fr       */
>>>>>>> 26cbcb6... Players wrappers debuged + Players initialize done. TODO: Sort players by ID
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_cw(t_cw *cw)
{
	destroy_arena(cw);
	destroy_all_carries(cw);
	destroy_all_plys(cw);
}