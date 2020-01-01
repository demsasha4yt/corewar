/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 20:23:07 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/01 21:01:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	read_name(char *line, int fd, t_asm *_asm)
{
	char *ptr;
	(void)fd;

	validate_name(line, _asm);
	ptr = ft_strchr(line, '\"');
	if (!ptr)
		terminate(3, &_asm);
	ptr++;
	ft_printf(ptr);
}