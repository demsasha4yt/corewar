/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:53:23 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/17 21:43:19 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

void		read_file(t_asm *_asm)
{
	int		fd;
	char	*code;

	fd = open(_asm->file_path, O_RDONLY);
	if (fd == -1)
		terminate(2, &_asm);
	while (get_next_line(fd, &code) > 0)
	{
		if (ft_strstr(code, NAME_CMD_STRING))
			read_name(code, fd, _asm);
		else if (ft_strstr(code, COMMENT_CMD_STRING))
			read_comment(code, fd, _asm);
		else if (!is_comment_ch(code))
			read_cmds(code, fd, _asm);
		ft_strdel(&code);
	}
	ft_printf("%s\n", _asm->name);
	ft_printf("%s\n", _asm->comment);
	close(fd);
}