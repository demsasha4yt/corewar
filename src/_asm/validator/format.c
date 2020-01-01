/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:45:57 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/01 20:25:52 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	validate_format(t_asm *_asm)
{
	const size_t	len = ft_strlen(_asm->file_path);

	if (_asm->file_path[len -1] != 's' && _asm->file_path[len - 2] != '.')
		terminate(1, &_asm);
}