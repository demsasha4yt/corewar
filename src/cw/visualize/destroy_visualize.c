/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_visualize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:43:27 by tlynesse          #+#    #+#             */
/*   Updated: 2020/01/26 19:43:56 by tlynesse         ###   ########.fr       */
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