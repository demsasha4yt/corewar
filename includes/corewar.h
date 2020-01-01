/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:27:46 by bharrold          #+#    #+#             */
/*   Updated: 2019/11/17 18:26:40 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"

typedef enum	e_errors
{
	ARGV_OUT_OF_ARRAY = 1,
	PLAYERS_FULL,
	INVALID_PLAYER_NUMBER
}				t_errors;

typedef struct	s_player {
	int		number;
	char	*src_file;
	char	*name[PROG_NAME_LENGTH + 1];
}				t_player;

typedef struct	s_cw {
	int			players_cnt;
	t_player	*players[MAX_PLAYERS];
}				t_cw;

/*
** Parse
*/

void		parse_argv (t_cw *cw, int argc, char **argv);

/*
** Validations args
*/

int				is_no_params(int argc);
int				is_nflag(char *arg);


/*
** Constructors & Destructors
*/
t_player		*new_player(char *src_file);

/*
** Other utils
*/
void			terminate(t_cw *cw, int error_code, const char *reason);

#endif