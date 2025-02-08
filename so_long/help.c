/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:54:55 by meid              #+#    #+#             */
/*   Updated: 2024/10/18 08:07:31 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	help(t_so_info *i, int add_y, int add_x, int flag)
{
	i->arr_file[i->player.y + add_y][i->player.x + add_x] = '0';
	draw_whole_map(i, i->player.player_dir);
	i->arr_file[i->player.y][i->player.x] = '0';
	i->arr_file[i->player.y + add_y][i->player.x + add_x] = 'P';
	if (flag == 1)
		i->player.c_c_coin += 1;
	if (flag == 3)
		destroy_everything(i);
	i->player.moves += 1;
	i->player.x += add_x;
	i->player.y += add_y;
	draw_whole_map(i, i->player.player_dir);
	if (i->flag.part == 'm')
		ft_printf("the player move num : %d \n", i->player.moves);
	else
	{
		i->numstr = ft_itoa(i->player.moves);
		i->numstr2 = ft_strjoin("move num : ", i->numstr);
		mlx_string_put(i->mlx, i->win.mlx_win, 42, 22, 0xFFFFFF, i->numstr2);
		free(i->numstr);
		free(i->numstr2);
	}
	return (0);
}
