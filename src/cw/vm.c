/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:46:19 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/01 18:56:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm	*create_vm()
{
	t_vm	*vm;

	vm = (t_vm*)ft_memalloc(sizeof(t_vm));
	return (vm);
}

void	destroy_vm(t_vm **vm)
{
	free(*vm);
	*vm = NULL;
}