/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visualize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:18:59 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/23 23:32:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		init_screen()
{
	initscr();
	raw();
	noecho();
	cbreak();
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_BLUE);
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);
}

static void		set_sizes(t_cw *cw)
{
	if (!cw->vis)
		terminate(2, cw);
	getmaxyx(stdscr, cw->vis->maxy, cw->vis->maxx);
}

void			init_visualize(t_cw *cw)
{
	if (!cw->visualize_active) 
		return ;
	init_screen();
	if (cw->vis)
		terminate(2, cw);
	cw->vis = (t_vis*)ft_memalloc(sizeof(t_vis));
	set_sizes(cw);
	cw->vis->map = newwin(cw->vis->maxy / 10 * 9, 
	cw->vis->maxx, 0, 0);
	refresh();
}