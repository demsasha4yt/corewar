/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_asm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:29:45 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/01 19:59:59 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm	*create_asm()
{
	t_asm	*_asm;

	if (!(_asm = (t_asm*)ft_memalloc(sizeof(t_asm))))
		exit(2048);
	_asm->file_path = NULL;
	_asm->name = NULL;
	_asm->comment = NULL;
	_asm->label = NULL;
	_asm->output = NULL;
	return (_asm);
}

void	destroy_asm(t_asm **_asm)
{
	// free((*_asm)->file_path);
	// free((*_asm)->name);
	// free((*_asm)->comment);
	// free((*_asm)->label);
	// free((*_asm)->output);
	free(*_asm);
	
	*_asm = NULL;
}