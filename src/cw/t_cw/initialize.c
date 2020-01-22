/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:22:26 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/22 19:49:08 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	initialize_cw(t_cw *cw)
{
	cw->cycles = 0;
	cw->live_count = 0;
	cw->cycles_to_die = CYCLE_TO_DIE;
	cw->count_players = 0;
	cw->arena = NULL;
	cw->carries_count = 0;
	cw->carries = NULL;
	cw->players = NULL;
	cw->last_alive = NULL;
}