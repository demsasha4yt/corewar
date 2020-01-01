/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 20:30:41 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/01 20:51:11 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		validate_name(char *line, t_asm *_asm)
{
	char	*ptr;
	const size_t len = ft_strlen(NAME_CMD_STRING);

	ptr = line;
	while (*ptr != '.')
		(*ptr != ' ' && *ptr != '\t') ? terminate(3, &_asm) : ptr++;
	if (*ptr != '.')
		terminate(3, &_asm);
	
	if (!ft_strnstr(ptr, NAME_CMD_STRING, len))
		terminate(3, &_asm);
	ptr += len;
	while (*ptr != '\"')
		(*ptr != ' ' && *ptr != '\t') ? terminate(3, &_asm) : ptr++;
}