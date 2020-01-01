/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:27:00 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/01 21:01:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	terminate(int code, t_asm **_asm)
{
	if (code == 1)
		write(2, "Usage: /asm [path to the champion_file.s]\n", 43);
	if (code == 2)
		write(2, "ASM Error: No such file.\n", 27);
	if (code == 3)
		write(2, "ASM Error: Name incorect\n", 26);
	destroy_asm(_asm);
	exit(code);
}