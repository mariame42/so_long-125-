/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:47:06 by meid              #+#    #+#             */
/*   Updated: 2024/10/18 07:02:35 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	press_to_start(t_so_info *i)
{
	i->mlx = mlx_init();
	i->win.mlx_win = mlx_new_window(i->mlx, i->win.width * DIM, i->win.height
			* DIM, "luffy : )");
	create_album(i);
	mlx_hook(i->win.mlx_win, 17, 0L, destroy_everything, i);
	draw_map_background(i);
	draw_whole_map(i, i->player.player_dir);
	mlx_key_hook(i->win.mlx_win, key_hook, i);
	if (i->flag.part == 'b')
	{
		mlx_loop_hook(i->mlx, animation, i);
	}
	mlx_loop(i->mlx);
}

int	animation(t_so_info *i)
{
	int	x;
	int	y;

	x = i->enemy_x;
	y = i->enemy_x;
	while (i->arr_file[x])
	{
		y = 0;
		while (i->arr_file[x][y])
		{
			if (i->arr_file[x][y] == 'N')
			{
				draw_enemy(i, x, y);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	draw_floor(t_so_info *i, int j, int k)
{
	mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[FLOOR].img, k
		* DIM, j * DIM);
}

void	draw_enemy_frame(t_so_info *i, int j, int k, int l)
{
	if (l < 10)
		mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[frame0].img, k
			* DIM, j * DIM);
	else if (l < 20)
		mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[frame1].img, k
			* DIM, j * DIM);
	else if (l < 30)
		mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[frame2].img, k
			* DIM, j * DIM);
	else if (l < 40)
		mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[frame3].img, k
			* DIM, j * DIM);
	else if (l < 50)
		mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[frame4].img, k
			* DIM, j * DIM);
	else if (l < 60)
		mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[frame5].img, k
			* DIM, j * DIM);
	else if (l < 70)
		mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[frame6].img, k
			* DIM, j * DIM);
}

void	draw_enemy(t_so_info *i, int j, int k)
{
	static int	l;

	draw_floor(i, j, k);
	draw_enemy_frame(i, j, k, l);
	l++;
	if (l == 70)
		l = 0;
}
