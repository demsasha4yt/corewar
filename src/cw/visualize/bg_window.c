/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 23:00:02 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/23 23:20:34 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_color_on(WINDOW *w, short color1, short color2)
{
	init_pair(1, color1, color2);
	wattron(w, COLOR_PAIR(1));
}

void	set_color_off()
{
	attroff(COLOR_PAIR(1));
}