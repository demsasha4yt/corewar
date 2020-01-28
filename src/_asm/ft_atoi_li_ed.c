/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:50:36 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/13 18:37:57 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_atoi_asm_ed(char *str, t_farm *farm)
{
	int				result;
	int				s;
	long int		n;

	s = 1;
	n = 0;
	if (*str && ((*str == '-') || (*str == '+')))
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		if (n * s < -2147483648 || n * s > 2147483647)
			li_error(farm);
		str++;
	}
	result = s * n;
	return (result);
}
