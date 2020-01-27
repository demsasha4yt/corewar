/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:26:04 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/26 23:00:39 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*read_code(int fd, int size, t_cw *cw)
{
	char	*code;
	
	if (!(code = ft_strnew(size)))
		terminate(1, cw);
	if (read(fd, code, size) != size)
		terminate(1, cw);
	return (code);
}