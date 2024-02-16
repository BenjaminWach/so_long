/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:13:03 by bwach             #+#    #+#             */
/*   Updated: 2024/02/16 15:11:01 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFERSIZE
#  define BUFFERSIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include <sys/time.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdbool.h>

//Error_code
# define ERR_ARG "Error:\nInvalid numbers of arguments: ./so_long 'map'" 
# define ERR_FILE "Error:\nOpen: map file: FAILED or NULL"
# define ERR_SPRITE_FILE "Error:\nXPM category not found"
# define ERR_INIT "Error:\nInit of map FAILED or NULL"
# define ERR_WIN "Error:\nCreation of the window: FAILED or NULL"
# define ERR_ALLOC "Error:\nAllocation of memory: FAILED or NULL"
# define ERR_CPY "Error:\nCopying the og map into the cpy failed!"

# define ERR_MAP "Error:\nThere is an error within the map\n"
# define POS_NOT_FOUND "Error:\n Position of the item not found\n"
# define ERR_BASE_MAP "Error:\nNeed at least 1 exit, 1 character, 1 conso\n"
# define ERR_MAP_SIZE "Error:\nMap have wrong dimensions(x, y)\n"
# define ERR_NO_END "Error:\nCannot access either objects or the exit:\n"
# define ERR_NO_EXIT "No exit found.\n"

//Keycodes
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_RST 15
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define ARROW_DW 125
# define ESC 53
# define KEY_ACTION 14

typedef struct s_position
{
	int		x;
	int		y;
}	t_pos;

/* pos: position en pixel
   lpos: derniere pos
   hg, hd, g, d: positions coin joueur
   ac: actions
   direction: sens.*/
typedef struct s_play
{
	int		pos[2];
	int		lpos[2];
	int		hg[2];
	int		hd[2];
	int		g[2];
	int		d[2];
	int		ac[3];
	int		direction;
	bool	moving;
}	t_play;

typedef struct s_map
{
	char	**map;
	int		**walls_sp;
	int		width;
	int		height;
	int		fd;
	int		nb_obj;
	char	*str;
	t_pos	*exit;
}	t_map;

typedef struct s_data
{
	int			fps;
	int			moves;
	int			anim_idx;
	char		*path;
	char		**cpy_map;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*env[8];
	void		*obj[2];
	void		*door[2];
	void		*p[12];
	void		*p_mv[16];
	void		*p_atk[46];
	bool		reset;
	t_map		*map;
	t_play		*player;
	long long	last_time;
}	t_data;

//main
int			main(int argc, char **argv);
void		init_game_mlx(t_data *game, char **argv);
int			valid_map(t_map *map);
void		init_sprites(t_data *game);

long long	time_now(void);
void		frame_per_second(t_data *game);
int			run_loop(t_data *game);
void		draw_pic(int x, int y, void *sprite, t_data *game);

//player
void		player(t_data *game);
void		move_right(t_data *game, t_play *p);
void		move_left(t_data *game, t_play *p);
void		move_up(t_data *game, t_play *p);
void		move_dwn(t_data *game, t_play *p);

//map
int			check_fill(t_map *map, t_pos *exit);
int			get_height(t_map *map);
int			get_width(t_map *map);
void		exit_pos(t_map *map);

//sprite
void		environment(t_data *game, t_map *m);
void		forest(t_data *game, t_map *m);
void		chest(t_data *game, t_map *m);
void		castle(t_data *game, t_map *m);

//keycode
void		key_hooks(t_data *game);
void		set_action(int keycode, t_data *game);
void		unset_action(int keycode, t_data *game);

//errors
void		error_msg(char *msg);
void		error_map(char *msg, int err);
char		free_and_alloc(char *str);

//utils
int			**allocate_tab_memset(t_map *map);
void		print_map(t_map *map);
void		print_visited(int **visited, int height, int width);

#endif