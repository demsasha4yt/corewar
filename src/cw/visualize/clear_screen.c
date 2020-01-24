/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/cw/visualize/clear_screen.c
/*   Created: 2020/01/22 20:59:49 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/23 20:04:18 by bharrold         ###   ########.fr       */
=======
/*   Created: 2020/01/24 19:25:50 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/24 21:36:03 by bharrold         ###   ########.fr       */
>>>>>>> 26cbcb6... Players wrappers debuged + Players initialize done. TODO: Sort players by ID:src/cw/t_ply/sort_plys.c
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void clear_screen()
{
<<<<<<< HEAD:src/cw/visualize/clear_screen.c
	const char *clean_screen_ansi = "\e[1;1H\e[2J";
	
	write(0, clean_screen_ansi, 12);
=======
	if (!cw)
		terminate(3, cw);
	if (!cw->players)
		terminate(3, cw);
	/**
	 * TODO SORT PLAYERS
	 */
>>>>>>> 26cbcb6... Players wrappers debuged + Players initialize done. TODO: Sort players by ID:src/cw/t_ply/sort_plys.c
}