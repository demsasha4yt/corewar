/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 20:23:07 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/17 21:33:37 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void _terminate (t_asm *_asm)
{
	terminate(3, &_asm);
}

static void	realloc_join_name(t_asm *_asm, char *line)
{
	char	*ptr;
	char	*tmp;
	
	ptr = line;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	tmp = _asm->name;
	_asm->name = ft_strjoin(tmp, ptr);
	free(tmp);
}

static void read_name_until_end(int fd, t_asm *_asm) 
{
	char	*ptr;
	char	*line;
	
	if (get_next_line(fd, &line) == -1)
		_terminate(_asm);
	if (line == NULL)
		_terminate(_asm);
	while (!(ptr = ft_strchr(line, '\"'))) {
		validate_name_second_str(line, _asm);
		realloc_join_name(_asm, line);
		ft_strdel(&line);
		line = NULL;
		if (get_next_line(fd, &line) == -1)
			_terminate(_asm);
		if (line == NULL)
			_terminate(_asm);
	}
	validate_name_last_str(line, _asm);
	*ptr = 0;
	realloc_join_name(_asm, line);
	ft_strdel(&line);
}

void		read_name(char *line, int fd, t_asm *_asm)
{
	char	*ptr;
	char	*tmp;
	char	*name;

	validate_name(line, _asm);
	ptr = ft_strchr(line, '\"');
	ptr++;
	tmp = ft_strchr(ptr, '\"');
	if (tmp == NULL) {
		realloc_join_name(_asm, ptr);
		read_name_until_end(fd, _asm);
		return ;
	}
	name = ft_strnew(tmp - ptr);
	ft_strncpy(name, ptr, tmp - ptr);
	_asm->name = name;
}