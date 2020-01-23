/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:27:46 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/23 23:10:17 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <curses.h>

typedef	struct		s_ply
{
	int				id;
	char			*name;
	char			*comment;
	int				code_size;
	char			*ply_code;
	char			*file_path;
	struct s_ply	*next;
	struct s_ply	*prev;
}					t_ply;

typedef struct		s_arena
{
	char			*data;
	int				arena_size;
	int				sections[MAX_PLAYERS];
} 					t_arena;

typedef struct		s_carry
{
	int				id;
	int				flag;
	int				live_cycle;
	int				cycles_left;
	int				position;
	int				registers[REG_NUMBER];
	int				player;
	struct s_carry	*next;
	struct s_carry	*prev;
}					t_carry;

typedef struct		s_vis
{
	int				maxx;
	int				maxy;
	WINDOW			*map;
	WINDOW			*info;
}					t_vis;

typedef struct		s_cw
{
	int				visualize_active;
	int				dump_cycles;
	int				d_cycles;
	int				cycles;
	int				live_count;
	int				cycles_to_die;
	int				count_players;
	t_arena			*arena;
	int				carries_count;
	t_carry			*carries;
	t_ply			*players;
	t_ply			*last_alive;
	t_vis			*vis;
}					t_cw;

void				terminate(int code, t_cw *cw);

void				initialize_arena(t_cw *cw);
void				destroy_arena(t_cw *cw);
int					get_player_in_byte(t_cw *cw, int byte);

t_carry				*new_carry(t_cw *cw);
void				push_new_carry(t_cw *cw, int byte, int player);
void				destroy_carry(t_carry *carry);
void				destroy_all_carries(t_cw *cw);

void				initialize_cw(t_cw *cw);
void				destroy_cw(t_cw *cw);

int					reader(t_cw *cw, int ac, char **av);
int					validate(int fd, char **name, char **exec, char **cmnt);

/*
 * Main algo 
*/
void				main_cycle(t_cw *cw);


// visualization
void				init_visualize(t_cw *cw);
void				destroy_visualize(t_cw *cw);
void				render(t_cw *cw);
void				set_color_on(WINDOW *w, short color1, short color2);
void				set_color_off();
#endif