/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_an_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:09:18 by meid              #+#    #+#             */
/*   Updated: 2024/10/14 08:30:58 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_album(t_so_info *i)
{
	i->imges[WALL].img = mlx_xpm_file_to_image(i->mlx, "images/water.xpm",
			&i->imges[WALL].img_width, &i->imges[WALL].img_height);
	i->imges[COIN].img = mlx_xpm_file_to_image(i->mlx, "images/meat.xpm",
			&i->imges[COIN].img_width, &i->imges[COIN].img_height);
	i->imges[PLAYER_R].img = mlx_xpm_file_to_image(i->mlx, "images/r_luffy.xpm",
			&i->imges[PLAYER_R].img_width, &i->imges[PLAYER_R].img_height);
	i->imges[PLAYER_L].img = mlx_xpm_file_to_image(i->mlx, "images/luffy.xpm",
			&i->imges[PLAYER_L].img_width, &i->imges[PLAYER_L].img_height);
	i->imges[EXIT].img = mlx_xpm_file_to_image(i->mlx, "images/win.xpm",
			&i->imges[EXIT].img_width, &i->imges[EXIT].img_height);
	i->imges[FLOOR].img = mlx_xpm_file_to_image(i->mlx, "images/wood.xpm",
			&i->imges[FLOOR].img_width, &i->imges[FLOOR].img_height);
	if (i->flag.part == 'b')
		enemy_imges(i);
}

void	draw_map_background(t_so_info *i)
{
	int	x;
	int	y;

	x = 0;
	while (i->arr_file[x])
	{
		y = 0;
		while (i->arr_file[x][y])
		{
			if (i->arr_file[x][y] != '1')
			{
				mlx_put_image_to_window(i->mlx, i->win.mlx_win,
					i->imges[FLOOR].img, y * DIM, x * DIM);
			}
			y++;
		}
		x++;
	}
}

void	draw_whole_map(t_so_info *i, int flag)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (i->arr_file[x])
	{
		y = 0;
		while (i->arr_file[x][y])
		{
			draw_the_element(i, x, y, flag);
			y++;
		}
		x++;
	}
}

void	draw_the_element(t_so_info *i, int j, int k, int flag)
{
	if (i->arr_file[j][k] == '1')
		mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[WALL].img, k
			* DIM, j * DIM);
	else if (i->arr_file[j][k] == 'C')
		mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[COIN].img, k
			* DIM, j * DIM);
	else if (i->arr_file[j][k] == 'P' && flag == 1)
		mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[PLAYER_R].img,
			k * DIM, j * DIM);
	else if (i->arr_file[j][k] == 'P' && flag == 2)
		mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[PLAYER_L].img,
			k * DIM, j * DIM);
	else if (i->arr_file[j][k] == 'E')
		mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[EXIT].img, k
			* DIM, j * DIM);
	else if (i->arr_file[j][k] == '0')
		mlx_put_image_to_window(i->mlx, i->win.mlx_win, i->imges[FLOOR].img, k
			* DIM, j * DIM);
}

void	enemy_imges(t_so_info *i)
{
	i->imges[frame0].img = mlx_xpm_file_to_image(i->mlx, "new_images/00.xpm",
			&i->imges[frame0].img_width, &i->imges[frame0].img_height);
	i->imges[frame1].img = mlx_xpm_file_to_image(i->mlx, "new_images/01.xpm",
			&i->imges[frame1].img_width, &i->imges[frame1].img_height);
	i->imges[frame2].img = mlx_xpm_file_to_image(i->mlx, "new_images/02.xpm",
			&i->imges[frame2].img_width, &i->imges[frame2].img_height);
	i->imges[frame3].img = mlx_xpm_file_to_image(i->mlx, "new_images/03.xpm",
			&i->imges[frame3].img_width, &i->imges[frame3].img_height);
	i->imges[frame4].img = mlx_xpm_file_to_image(i->mlx, "new_images/04.xpm",
			&i->imges[frame4].img_width, &i->imges[frame4].img_height);
	i->imges[frame5].img = mlx_xpm_file_to_image(i->mlx, "new_images/05.xpm",
			&i->imges[frame5].img_width, &i->imges[frame5].img_height);
	i->imges[frame6].img = mlx_xpm_file_to_image(i->mlx, "new_images/06.xpm",
			&i->imges[frame6].img_width, &i->imges[frame6].img_height);
}
