/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_v_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:35:51 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/26 20:44:29 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_v_flag(t_cw *cw, int *i, char **argv)
{
	(void)i;
	(void)argv;
	cw->visualize_active = 1;
}