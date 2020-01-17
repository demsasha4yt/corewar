/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 20:23:07 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/17 21:35:32 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void _terminate (t_asm *_asm)
{
	terminate(3, &_asm);
}

static void	realloc_join_comment(t_asm *_asm, char *line)
{
	char	*ptr;
	char	*tmp;
	
	ptr = line;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	tmp = _asm->comment;
	_asm->comment = ft_strjoin(tmp, ptr);
	free(tmp);
}

static void read_comment_until_end(int fd, t_asm *_asm) 
{
	char	*ptr;
	char	*line;
	
	if (get_next_line(fd, &line) == -1)
		_terminate(_asm);
	if (line == NULL)
		_terminate(_asm);
	while (!(ptr = ft_strchr(line, '\"'))) {
		validate_comment_second_str(line, _asm);
		realloc_join_comment(_asm, line);
		ft_strdel(&line);
		line = NULL;
		if (get_next_line(fd, &line) == -1)
			_terminate(_asm);
		if (line == NULL)
			_terminate(_asm);
	}
	validate_comment_last_str(line, _asm);
	*ptr = 0;
	realloc_join_comment(_asm, line);
	ft_strdel(&line);
}

void		read_comment(char *line, int fd, t_asm *_asm)
{
	char	*ptr;
	char	*tmp;
	char	*comment;

	validate_comment(line, _asm);
	ptr = ft_strchr(line, '\"');
	ptr++;
	tmp = ft_strchr(ptr, '\"');
	if (tmp == NULL) {
		realloc_join_comment(_asm, ptr);
		read_comment_until_end(fd, _asm);
		return ;
	}
	comment = ft_strnew(tmp - ptr);
	ft_strncpy(comment, ptr, tmp - ptr);
	_asm->comment = comment;
}