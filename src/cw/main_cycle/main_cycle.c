/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:07:58 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/31 19:46:56 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

void	main_cycle(t_cw *cw)
{
	while (true) 
	{
		cw->cycles++;
		render(cw);
		if (cw->cycles == 2) {
			break ;
		}
	}
}
