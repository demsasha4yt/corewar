/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_visualize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:39:33 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/23 22:02:43 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		destroy_visualize(t_cw *cw)
{
	if (!cw->vis)
		return ;
	free(cw->vis);
	endwin();
}