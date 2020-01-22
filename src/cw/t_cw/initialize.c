/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:22:26 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/22 17:25:53 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	initialize_cw(t_cw *cw)
{
	cw->count_players = 0;
	cw->arena = NULL;
	cw->carries = NULL;
	cw->players = NULL;
}