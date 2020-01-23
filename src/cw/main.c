/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:04:22 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/23 23:31:51 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main (int argc, char **argv)
{
	t_cw	cw;
	
	(void)argc;
	(void)argv;
  	initialize_cw(&cw);
	cw.count_players = 4;
	cw.visualize_active = 1;

	initialize_arena(&cw);
	init_visualize(&cw);
	main_cycle(&cw);
	destroy_visualize(&cw);
	destroy_cw(&cw);	
}

// push_new_carry(&cw, 1000, 2);
// push_new_carry(&cw, 6000, 3);
// push_new_carry(&cw, 1025, 4);
// ft_printf("arena sections: [%i, %i, %i, %i]\n", cw.arena->sections[0],cw.arena->sections[1], cw.arena->sections[2], cw.arena->sections[3]);
// ft_printf("%d\n", get_player_in_byte(&cw, 4095 + 1024));