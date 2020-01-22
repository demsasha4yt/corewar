/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:59:49 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/22 21:02:14 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void clear_screen()
{
	const char *clean_screen_ansi = "\e[1;1H\e[2J";
	
	write(0, clean_screen_ansi, 12);
}