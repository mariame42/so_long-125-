/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:43:48 by meid              #+#    #+#             */
/*   Updated: 2024/10/18 07:54:44 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
// # include "libft/libft.h"

# include <fcntl.h>  //open
# include <stdio.h>  //perror , strerror
# include <stdlib.h> // malloc , free , exit
# include <string.h>
# include <unistd.h> // read , write , close
# include <pthread.h>

# define DIM 48
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

enum
{
	WALL,
	COIN,
	PLAYER_R,
	PLAYER_L,
	EXIT,
	FLOOR,
	frame0,
	frame1,
	frame2,
	frame3,
	frame4,
	frame5,
	frame6
};

typedef struct s_window
{
	int			width;
	int			height;
	void		*mlx_win;
}				t_window;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_image
{
	void		*img;
	int			img_width;
	int			img_height;
}				t_image;

typedef struct player
{
	int	player_dir;
	int	x;
	int	y;
	int	c_c_coin;
	int	moves;
}		t_player;

typedef struct flag
{
	int		move_dir;
	char	element;
	char	part;
	int		p_num;
}			t_flag;

typedef struct info
{
	t_image		imges[13];
	t_window	win;
	t_player	player;
	t_flag		flag;
	void		*mlx;
	char		*map_loc;
	t_list		*file_l;
	char		**arr_file;
	char		**path_check;
	int			x;
	int			y;
	int			c_num;
	int			enemy_x;
	int			enemy_y;
	int			index;
	char		*numstr;
	char		*numstr2;
}				t_so_info;
//x & y are the player pos

void			handle_error(char *msg, t_so_info *i, int flag);
void			check_the_map(t_so_info *i);
void			map_check(t_list *list, t_so_info *i);
void			check(char *con, char *part_to_check, char char_to_check,
					t_so_info *i);
t_so_info		info1(int ac, char *file_name, char flag);
void			free_info(t_so_info *i, int flag);

void			check_elements(t_so_info *i);
int				check_how_many(char check_char, t_so_info *i, int flag);
void			add_new_line(t_so_info *i);
void			check_path(t_so_info *i);
// int     free_array(char **array);
char			**list_to_array(t_so_info *i);
void			player_pos(t_so_info *i);
int				ft_strchr_pos(char *str, char c);
void			rectangular_check(t_so_info *i);
void			check_for_extra_element(t_so_info *i);

/*start*/

void			press_to_start(t_so_info *i);
void			print_info(t_so_info *i);
void			create_album(t_so_info *i);
int				destroy_everything(t_so_info *i);
void			draw_map_background(t_so_info *i);
void			draw_whole_map(t_so_info *i, int flag);
void			draw_the_element(t_so_info *i, int j, int k, int flag);
int				key_hook(int keycod, t_so_info *i);
void			enemy_imges(t_so_info *i);
int				animation(t_so_info *i);
void			draw_enemy(t_so_info *i, int j, int k);
void			draw_floor(t_so_info *i, int j, int k);
void			draw_enemy_frame(t_so_info *i, int j, int k, int l);
/*=================== movement.c ======================*/
int				move(t_so_info *i, int add_y, int add_x);
int				move_up(t_so_info *i);
int				move_right(t_so_info *i);
int				move_down(t_so_info *i);
int				move_left(t_so_info *i);
int				help(t_so_info *i, int add_y, int add_x, int flag);
void			display_message(void *mlx_ptr, void *win_ptr, int win_width,
					int win_height);
void			call_path(t_so_info *i);
char			*ft_itoa(int n);
char			**make_area(char **zone, t_point size);
void			flood_fill(char **tab, t_point size, t_point begin);
void			fill(char **tab, t_point size, t_point cur, char to_fill);
void			fill2(char **tab, t_point size, t_point cur, char to_fill);
void			fill3(char **tab, t_point size, t_point cur, char to_fill);

#endif
