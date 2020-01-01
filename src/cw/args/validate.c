/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:56:06 by bharrold          #+#    #+#             */
/*   Updated: 2019/11/17 18:21:50 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_no_params(int argc)
{
	if (argc < 2)
		return (1);
	return (0);
}

int	is_nflag(char *arg)
{
	if (!ft_strcmp("-n", arg))
		return (1);
	return (0);
}
