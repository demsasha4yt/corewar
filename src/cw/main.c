/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:04:22 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/31 21:22:12 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

int main (int argc, char **argv)
{
	t_cw	cw;
	
  	initialize_cw(&cw);
	reader(&cw, argc, argv);
	initialize_plys(&cw);
	initialize_arena(&cw);
	initialize_carries(&cw);
	introduce_plys(&cw);
	init_visualize(&cw);
	main_cycle(&cw);
	destroy_cw(&cw);	
}
