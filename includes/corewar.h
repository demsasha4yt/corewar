/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:27:46 by bharrold          #+#    #+#             */
/*   Updated: 2020/01/29 22:06:30 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <curses.h>
# include <inttypes.h>

# define INT_SIZE 4

typedef	struct		s_ply
{
	int				id;
	char			*name;
	char			*comment;
	int				code_size;
	uint8_t			*code;
	char			*file_path;
	struct s_ply	*next;
	struct s_ply	*prev;
}					t_ply;

typedef struct		s_arena
{
	uint8_t			*data;
	int				arena_size;
	int				sections[MAX_PLAYERS];
}					t_arena;

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

/*
**	Reader
*/
void				reader(t_cw *cw, int ac, char **av);
void				read_champion(t_cw *cw, char *file);
void				read_n_flag(t_cw *cw, int *i, char **argv);
void				read_dump_flag(t_cw *cw, int *i, char **argv);
void				read_d_flag(t_cw *cw, int *i, char **argv);
void				read_v_flag(t_cw *cw, int *i, char **argv);
void				skip_bytes(int fd, t_cw *cw);

void				read_magic(int fd, t_cw *cw);
char				*read_name(int fd, t_cw *cw);
int					read_code_size(int fd, t_cw *cw);
char				*read_comment(int fd, t_cw *cw);
uint8_t				*read_code(int fd, int size, t_cw *cw);

/*
**	Validators
*/

int					cw_is_flag(char *str, char *flag);
int					cw_is_champion_file(char *str);

/*
 * CoreWar enviroment
*/

void				initialize_cw(t_cw *cw);
void				destroy_cw(t_cw *cw);

/*
 *	Players
*/

t_ply				*new_ply(int number, char *name, char *comment,
								uint8_t *code);
void				push_ply(t_cw *cw, t_ply *ply);
t_ply				*set_ply_code_size(t_ply *ply, int code_size, t_cw *cw);
t_ply 				*set_ply_code(t_ply *ply, uint8_t *code, 
						int code_size, t_cw *cw);
t_ply				*set_ply_file_path(t_ply *ply, char *file_path, t_cw *cw);
void				initialize_plys(t_cw *cw);
void				sort_plys(t_cw *cw);
void				destroy_ply(t_ply *ply);
void				destroy_all_plys(t_cw *cw);

/*
 * Carries
*/

t_carry				*new_carry(t_cw *cw);
t_carry				*push_new_carry(t_cw *cw, int byte, int player);
void				destroy_carry(t_carry *carry);
void				destroy_all_carries(t_cw *cw);
void				initialize_carries(t_cw *cw);

/*
 * Arena
*/
void				initialize_arena(t_cw *cw);
void				destroy_arena(t_cw *cw);
int					get_player_in_byte(t_cw *cw, int byte);

/*
 * Main algo 
*/
void				main_cycle(t_cw *cw);


/*
** UTILS
*/

int					calc_addr(int addr);
int					bytes_to_int(int8_t *bytes, size_t size);

// visualization
void				init_visualize(t_cw *cw);
void				destroy_visualize(t_cw *cw);
void				render(t_cw *cw);
void				set_color_on(WINDOW *w, short color1, short color2);
void				set_color_off();

#endif