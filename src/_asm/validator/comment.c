/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 20:30:45 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/17 21:30:22 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	_terminate(char *line, t_asm *_asm)
{
	free(line);
	terminate(4, &_asm);
}

void		validate_comment(char *line, t_asm *_asm)
{
	char	*ptr;
	const size_t len = ft_strlen(COMMENT_CMD_STRING);

	ptr = line;
	while (*ptr != '.')
		(*ptr != ' ' && *ptr != '\t') ? _terminate(line, _asm) : ptr++;
	if (*ptr != '.')
		_terminate(line, _asm);
	if (!ft_strnstr(ptr, COMMENT_CMD_STRING, len))
		_terminate(line, _asm);
	ptr += len;
	while (*ptr != '\"')
		(*ptr != ' ' && *ptr != '\t') ? _terminate(line, _asm) : ptr++;
}

void		validate_comment_second_str(char *line, t_asm *_asm)
{
	char	*ptr;
	
	(void)_asm;
	ptr = line;
	while (ptr && *ptr && (*ptr == ' ' || *ptr == '\t'))
		ptr++; 
}

void		validate_comment_last_str(char *line, t_asm *_asm)
{
	char	*ptr;
	char	*tmp;
	
	ptr = line;
	while (ptr && *ptr && (*ptr == ' ' || *ptr == '\t'))
		ptr++;
	tmp = ft_strchr(line, '\"');
	if (!tmp)
		_terminate (line, _asm);
	tmp++;
	while (tmp && *tmp)
	{
		if (*tmp == ' ' || *tmp == '\t')
		{
			tmp++;
			continue;
		}
		if (*tmp == '#' || *tmp == 0)
			return ;
		else
			_terminate (line, _asm);
	}
}