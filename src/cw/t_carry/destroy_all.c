/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:40:11 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/22 20:54:33 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_all_carries(t_cw *cw)
{
	t_carry		*ptr;
	t_carry		*next;
	
	if (!cw->carries)
		return ;
	ptr = cw->carries;
	while (ptr) {
		ft_printf("%p\n", ptr);
		next = ptr->next;
		destroy_carry(ptr);
		ptr = next;
	}
}