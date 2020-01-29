/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:26:04 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/29 21:46:52 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t	*read_code(int fd, int size, t_cw *cw)
{
	uint8_t	*code;
	
	if (!(code = (uint8_t*)ft_memalloc(size)))
		terminate(1, cw);
	if (read(fd, code, size) != size)
		terminate(1, cw);
	return (code);
}