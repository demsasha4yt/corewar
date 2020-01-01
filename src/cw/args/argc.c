/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:59:16 by bharrold          #+#    #+#             */
/*   Updated: 2019/11/17 18:27:24 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		find_first_players_clear_index(t_cw *cw)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (cw->players[i] == NULL)
			return (i);
	}
	return (-1);
}

static void		push_player(t_cw *cw, t_player *player, int number, int index)
{
	ft_printf("%i \n", number);
	if (number == -1)
		number = find_first_players_clear_index(cw);
	if (number == -1)
		terminate(cw, PLAYERS_FULL, "To much players...");
	if (number != -1 && cw->players[number] != NULL)
		terminate(cw, INVALID_PLAYER_NUMBER, "Invalid player number (flag -n)");
	else if (cw->players[number] != NULL)
		terminate(cw, INVALID_PLAYER_NUMBER, "LOL");
	else
	{
		player->number = index;
		cw->players[number] = player;
		cw->players_cnt++;
	}
}

void			parse_argv(t_cw *cw, int argc, char **argv)
{
	int i;
	int n;

	i = 0;
	while (++i < argc)
	{
		n = -1;
		if (is_nflag(argv[i]))
		{
			ft_printf("%i %i\n", i + 1, argc);
			if (i + 1 >= argc - 1)
				terminate(cw, ARGV_OUT_OF_ARRAY, "ARGV: Out of array");
			n = ft_atoi(argv[++i]);
		}
		push_player(cw, new_player(argv[i]), n, cw->players_cnt);
	}
	i = -1;
	while (++i < MAX_PLAYERS && cw->players[i] != NULL)
	{
		ft_printf("%i ", cw->players[i]->number);
	}
	ft_printf("\n");
}