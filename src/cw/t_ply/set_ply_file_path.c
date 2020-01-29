/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ply_file_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:21:27 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/29 20:44:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	_terminate(t_cw *cw, t_ply *ply)
{
	destroy_ply(ply);
	terminate(3, cw);
}

t_ply	*set_ply_file_path(t_ply *ply, char *file_path, t_cw *cw)
{
	if (!ply)
		terminate(3, cw);
	if (!file_path)
		_terminate(cw, ply);
	ply->file_path = ft_strdup(file_path);
	return (ply);
}