/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:32:51 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/05 22:09:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

static t_ply	*get_ply(t_cw *cw, int id)
{
	t_ply *ptr;

	ptr = cw->players;
	while (ptr)
	{
		if (ptr->id == id)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void	cw_live(t_cw *cw, t_carry *carry)
{
	ft_printf("Do op: \"live\" [CYCLE: %d CARRY: %d]\n", cw->cycles, carry->id);
	int		id;
	t_ply		*ply;

	printf("do op live\n");
	carry->step += OP_SIZE;
	id = get_argument(cw, carry, 1, false);
	cw->lives_num++;
	carry->live_cycle = cw->cycles;
	ply = NULL;
	if (id <= -1 && id >= -((int)cw->count_players))
	{
		ply = get_ply(cw, -id);
		if (!ply)
			terminate(10, cw);
		ply->live_cycle = cw->cycles;
		ply->lives_num++;
		cw->last_alive = ply;
	}
}
