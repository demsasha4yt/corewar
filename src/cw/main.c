/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:04:22 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/23 21:03:21 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main (int argc, char **argv)
{
	t_cw	cw;
	(void)argc;
	(void)argv;
  	initialize_cw(&cw);
	// reader(&cw, argc, argv);
	cw.count_players = 4;
	initialize_arena(&cw);
	push_new_carry(&cw, 1000, 2);
	push_new_carry(&cw, 6000, 3);
	push_new_carry(&cw, 1025, 4);
	destroy_cw(&cw);
	// ft_printf("arena sections: [%i, %i, %i, %i]\n", cw.arena->sections[0],cw.arena->sections[1], cw.arena->sections[2], cw.arena->sections[3]);
	// ft_printf("%d\n", get_player_in_byte(&cw, 4095 + 1024));
}