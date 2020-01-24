/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ply.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:14:30 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/24 20:06:16 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_ply	*new_ply(int number, char *name, char *comment, char *code)
{
	t_ply	*ply;
	
	if (!name || !comment || !code)
		return (NULL);
	ply = (t_ply*)ft_memalloc(sizeof(t_ply));
	if (!ply)
		return (NULL);
	ply->id = number;
	ply->name = ft_strdup(name);
	ply->comment = ft_strdup(comment);
	ply->code = ft_strdup(code);
	ply->code_size = ft_strlen(ply->code);
	ply->file_path = NULL;
	ply->next = NULL;
	ply->prev = NULL;
	return (ply);
}
