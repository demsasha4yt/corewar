/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:28:28 by bharrold          #+#    #+#             */
/*   Updated: 2019/11/17 17:55:13 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player	*new_player(char *src_file)
{
	t_player *new;

	new = (t_player*)malloc(sizeof(t_player));
	new->src_file = ft_strdup(src_file);
	return (new);
}
