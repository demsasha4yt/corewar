/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment_ch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:37:38 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/17 21:39:15 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_comment_ch(char *line)
{
	int i;

	i = 0;
	if (line[0] == '\0')
		return (1);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == COMMENT_CHAR)
	{
		if (line[i] == COMMENT_CHAR)
			return (1);
		i++;
	}
	return ((line[i] == '\0') ? 1 : 0);
}
