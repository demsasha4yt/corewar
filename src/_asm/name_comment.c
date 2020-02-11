/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:37:10 by kturnips          #+#    #+#             */
/*   Updated: 2020/02/11 14:07:08 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_name_p2(int i, t_asm *asm_ms)
{
	int		j;
	char	*str;
	int		check;

	asm_ms->name[i++] = '\n';
	while (get_next_line(asm_ms->fd_r, &str))
	{
		check = (!ft_strchr(str, '"')) ? 1 : 0;
		asm_ms->current_line += 1;
		j = 0;
		while (str[j] != '"' && str[j] && i < PROG_NAME_LENGTH)
			asm_ms->name[i++] = str[j++];
		check ? asm_ms->name[i++] = '\n' : 0;
		if (i > PROG_NAME_LENGTH)
			asm_error(17, asm_ms->current_line, asm_ms);
		if (str[j++] == '"')
		{
			while (str[j] == ' ' || str[j] == '\t')
				j++;
			if (str[j] != COMMENT_CHAR && str[j] != ALT_COMMENT_CHAR && str[j])
				asm_error(18, asm_ms->current_line, asm_ms);
			return ;
		}
		free(str);
	}
}

int		check_name_p1(char *str, t_asm *asm_ms, int i)
{
	asm_ms->name = (char *)ft_memalloc(sizeof(char) * PROG_NAME_LENGTH);
	str += 5;
	is_space(&str);
	if (*str++ == '"')
	{
		while (str[i] != '"' && str[i] && i < PROG_NAME_LENGTH)
		{
			asm_ms->name[i] = str[i];
			i++;
		}
		i > PROG_NAME_LENGTH ? asm_error(17, asm_ms->current_line, asm_ms) : 0;
		if (str[i] == '"')
		{
			i++;
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
				asm_error(18, asm_ms->current_line, asm_ms);
		}
		else
			check_name_p2(i, asm_ms);
	}
	else
		asm_error(21, asm_ms->current_line, asm_ms);
	return (1);
}

void	check_comment_p2(int i, t_asm *asm_ms)
{
	int		j;
	char	*str;
	int		check;

	asm_ms->comment[i++] = '\n';
	while (get_next_line(asm_ms->fd_r, &str))
	{
		check = (!ft_strchr(str, '"')) ? 1 : 0;
		asm_ms->current_line += 1;
		j = 0;
		while (str[j] != '"' && str[j] && i < COMMENT_LENGTH)
			asm_ms->comment[i++] = str[j++];
		check ? asm_ms->comment[i++] = '\n' : 0;
		if (i > COMMENT_LENGTH)
			asm_error(19, asm_ms->current_line, asm_ms);
		if (str[j++] == '"')
		{
			while (str[j] == ' ' || str[j] == '\t')
				j++;
			if (str[j] != COMMENT_CHAR && str[j] != ALT_COMMENT_CHAR && str[j])
				asm_error(20, asm_ms->current_line, asm_ms);
			return ;
		}
		free(str);
	}
}

int		check_comment_p1(char *str, t_asm *asm_ms, int i)
{
	asm_ms->comment = (char *)ft_memalloc(sizeof(char) * COMMENT_LENGTH);
	str += 8;
	is_space(&str);
	if (*str++ == '"')
	{
		while (str[i] != '"' && str[i] && i < COMMENT_LENGTH)
		{
			asm_ms->comment[i] = str[i];
			i++;
		}
		i > COMMENT_LENGTH ? asm_error(19, asm_ms->current_line, asm_ms) : 0;
		if (str[i] == '"')
		{
			i++;
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				i++;
			if (str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR && str[i])
				asm_error(20, asm_ms->current_line, asm_ms);
		}
		else
			check_comment_p2(i, asm_ms);
	}
	else
		asm_error(22, asm_ms->current_line, asm_ms);
	return (1);
}

int		check_name_comment(char *str1, t_asm *asm_ms)
{
	char *str;

	str = str1;
	if (*str)
	{
		if (*str == COMMENT_CHAR || *str == ALT_COMMENT_CHAR)
			return (1);
		if (ft_strncmp(str, NAME_CMD_STRING, 5) == 0 && asm_ms->name == NULL)
		{
			check_name_p1(str, asm_ms, 0);
		}
		else if (ft_strncmp(str, NAME_CMD_STRING, 5) == 0 && asm_ms->name
				!= NULL)
			asm_error(23, asm_ms->current_line, asm_ms);
		else if (ft_strncmp(str, COMMENT_CMD_STRING, 8) == 0
				&& asm_ms->comment == NULL)
			check_comment_p1(str, asm_ms, 0);
		else if (ft_strncmp(str, COMMENT_CMD_STRING, 8) == 0
				&& asm_ms->comment != NULL)
			asm_error(24, asm_ms->current_line, asm_ms);
		else if (!asm_ms->comment || !asm_ms->name)
			asm_error(25, asm_ms->current_line, asm_ms);
	}
	return (1);
}
