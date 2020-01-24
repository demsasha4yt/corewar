/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:12:50 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/24 20:02:02 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	_terminate(t_cw *cw, t_ply *ply)
{
	// TODO: Destroy player
	(void)ply;
	terminate(3, cw);
}

static void	_push_ply(t_cw *cw, t_ply *ply)
{
	t_ply *ptr;
	
	if (!cw->players)
	{
		cw->players = ply;
		ply->next = NULL;
		ply->prev = NULL;
		return ;
	}
	ptr = cw->players;
	while (ptr->next)
	{
		if (ptr->id == ply->id)
			_terminate(cw, ply);
		ptr = ptr->next;
	}
	ptr->next = ply;
	ply->prev = ptr;
	ply->next = NULL;
}

void	push_ply(t_cw *cw, t_ply *ply)
{
	if (!ply)
		terminate(3, cw);
	if (ply->id > MAX_PLAYERS)
		_terminate(cw, ply);
	if (!ply->file_path)
		_terminate(cw, ply);
	if (!ply->name)
		_terminate(cw, ply);
	if (!ply->comment)
		_terminate(cw, ply);
	if (!ply->code)
		_terminate(cw, ply);
	if (ply->code_size < 0 || ply->code_size > 682)
		_terminate(cw, ply);
	_push_ply(cw, ply);
}