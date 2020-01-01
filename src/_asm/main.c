/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:18:18 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/01 19:59:33 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int argc, char **argv)
{
	t_asm	*_asm;
	
	_asm = create_asm();
	if (argc != 2)
		terminate(1, &_asm);
	_asm->file_path = argv[1];
	validate_format(_asm);
	read_file(_asm);
	return (0);
}