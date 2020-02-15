/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:30:36 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/01 18:51:36 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main(int argc, char **argv)
{	
	t_vm	*vm;
	
	ft_printf("[VM] CW STARTED - [ARGS]: %d, %p\n", argc, argv);
	vm = create_vm();
	ft_printf("%p\n", vm);
	destroy_vm(&vm);
	ft_printf("%p\n", vm);
	return (0);
}