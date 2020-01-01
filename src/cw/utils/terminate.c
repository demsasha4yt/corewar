/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:30:07 by bharrold          #+#    #+#             */
/*   Updated: 2019/11/17 15:39:46 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	If error_code is 0 The program worked correctly
*/
void		terminate(t_cw *cw, int error_code, const char *reason)
{
	if (reason != NULL && error_code != 0)
		ft_printf("Corewar Error: [%s (error_code: %i)]", reason, error_code);
	/*
	**	TODO: Clear CW Object!!
	*/
	exit(error_code);
}