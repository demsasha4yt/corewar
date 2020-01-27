/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:26:19 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/26 22:58:34 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*read_comment(int fd, t_cw *cw)
{
	char	*comment;
	
	if (!(comment = ft_strnew(COMMENT_LENGTH)))
		terminate(1, cw);
	if (read(fd, comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		terminate(1, cw);
	return (comment);
}