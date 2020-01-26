/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:04:22 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/26 23:04:17 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main (int argc, char **argv)
{
	t_cw	cw;
	
	(void)argc;
	(void)argv;
  	initialize_cw(&cw);
	reader(&cw, argc, argv);
	// cw.visualize_active = 1;

	// push_ply(&cw, set_ply_file_path(new_ply(3, "name", "comment", "code"), 
	// 			"file_path", &cw));
	// push_ply(&cw, set_ply_file_path(new_ply(1, "name", "comment", "code"), 
	//  	"file_path", &cw));
	// push_ply(&cw, set_ply_file_path(new_ply(-1, "name", "comment", "code"), 
	// 		"file_path", &cw));
	// push_ply(&cw, set_ply_file_path(new_ply(-1, "name", "comment", "code"), 
	// 		"file_path", &cw));
	initialize_plys(&cw);
	initialize_arena(&cw);
	t_ply *ptr;
	ptr = cw.players;
	while (ptr)
	{
		ft_printf("%p %d\n", ptr, ptr->id);
		ptr = ptr->next;
	}
	init_visualize(&cw);
	main_cycle(&cw);
	destroy_visualize(&cw);
	destroy_cw(&cw);	
}