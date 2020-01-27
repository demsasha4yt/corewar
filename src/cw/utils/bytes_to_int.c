/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:30:05 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/26 22:42:14 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	bytes_to_int(char *bytes, size_t size)
{
	int result;
	int i;
	int sign;

	sign = (bytes[0] & 0x80);
	i = 0;
	result = 0;
	while (size)
	{
		if (!sign)
			result += (bytes[size -1] & 0xFF) << (8 * i);
		else
			result += (bytes[size -1]) << (8 * i);
		i++;
		size--;
	}
	if (sign)
		result = ~result;
	return (result);
}
