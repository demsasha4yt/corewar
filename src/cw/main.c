/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:04:22 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/29 22:08:53 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main (int argc, char **argv)
{
	t_cw	cw;
	
  	initialize_cw(&cw);
	reader(&cw, argc, argv);
	initialize_plys(&cw);
	initialize_arena(&cw);
	initialize_carries(&cw);

	// t_ply *ptr;
	// ptr = cw.players;
	// int i = 0;
	// while (i < 4096)
	// {
	// 	ft_printf("%.2X ", cw.arena->data[i], 1);
	// 	i++;
	// }
	
	init_visualize(&cw);
	main_cycle(&cw);
	destroy_visualize(&cw);
	destroy_cw(&cw);	
}