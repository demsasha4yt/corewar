/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:04:22 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/31 19:19:42 by bharrold         ###   ########.fr       */
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
	init_visualize(&cw);
	t_carry 	*ptr;
	ptr = cw.carries;
	while (ptr)
	{
		ft_printf("carry - %p\n", ptr);
		cycle_read_command(ptr, &cw);
		ptr = ptr->next;
	}
	main_cycle(&cw);
	destroy_visualize(&cw);
	destroy_cw(&cw);	
}
