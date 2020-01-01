/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:22:12 by bharrold          #+#    #+#             */
/*   Updated: 2019/11/17 18:26:48 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void 	parse_args (t_cw * cw, int argc, char **argv)
{
	if (is_no_params(argc)) {
		ft_printf("Usage: ./corewar Player1 Player2 ..\n");
		ft_printf("There should be at least one player.\n");
		exit(0);
	}
	parse_argv(cw, argc, argv);
	return ;
}

static void		init_cw(t_cw *cw)
{
	cw->players_cnt = 0;
	ft_bzero(cw->players, sizeof(t_player*) * MAX_PLAYERS);
}

int		main(int argc, char **argv)
{
	t_cw	cw;
	
	parse_args(&cw, argc, argv);
	return (0);
}