/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read_magic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:26:21 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/26 22:42:50 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_magic(int fd, t_cw *cw)
{
	char	*ptr;
	int		magic;

	if (!(ptr = ft_strnew(INT_SIZE)))
		terminate(1, cw);
	ft_strclr(ptr);
	if (read(fd, ptr, INT_SIZE) != INT_SIZE)
		terminate(1, cw);
	magic = bytes_to_int(ptr, INT_SIZE);
	if (magic != COREWAR_EXEC_MAGIC)
		terminate(1, cw);
	free(ptr);
	return ;
}