/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_d_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:23:27 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/26 20:47:35 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		read_d_flag(t_cw *cw, int *i, char **argv)
{
	*i += 1;
	if (!ft_isnumber(argv[*i]))
		terminate(5, cw);
	cw->d_cycles = ft_atoi(argv[*i]);
}