/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 22:28:23 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 08:11:13 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void choose_color(t_cw *cw, int byte)
{
	const int player = get_player_in_byte(cw, byte);
	wattron(cw->vis->map, COLOR_PAIR(player));
}

static void	render_map(t_cw *cw)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	wclear(cw->vis->map);
	while (i < cw->arena->arena_size)
	{
		wmove(cw->vis->map, j, k);
		choose_color(cw, i);
		wprintw(cw->vis->map, "%.2x", cw->arena->data[i]);
		if ((i + 1) % (cw->vis->maxx / 3) == 0)
		{
			k = 0;
			j += 1;
		}
		else
			k += 3;
		i++;
	}
	wrefresh(cw->vis->map);
}

static void	render_info(t_cw *cw)
{
	box (cw->vis->info, 0, 0);
	wrefresh(cw->vis->info);
}

void	render(t_cw *cw)
{
	if ((cw->v & 2048) == 0) 
		return ;
	render_map(cw);
	render_info(cw);
	getch();
}
