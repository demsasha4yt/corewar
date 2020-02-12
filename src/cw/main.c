/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:04:22 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 07:24:33 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

static void print_winner(t_cw *cw)
{
	if (!cw->last_alive) {
		terminate(10, cw);
	}
	ft_printf("Contestant %d, \"%s\", has won !\n",
		cw->last_alive->id,
		cw->last_alive->name);
}

int		main (int argc, char **argv)
{
	t_cw	cw;
	
  	initialize_cw(&cw);
	reader(&cw, argc, argv);
	initialize_plys(&cw);
	cw.last_alive = cw.players;
	initialize_arena(&cw);
	initialize_carries(&cw);
	introduce_plys(&cw);
	init_visualize(&cw);
	main_cycle(&cw);
	print_winner(&cw);
	destroy_cw(&cw);	
}
