/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:47:21 by meid              #+#    #+#             */
/*   Updated: 2024/10/15 11:47:54 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_so_info *i)
{
	int	add_y;
	int	add_x;

	add_y = 0;
	add_x = 0;
	if (keycode == W_KEY)
		add_y -= 1;
	else if (keycode == D_KEY)
	{
		i->player.player_dir = 1;
		add_x += 1;
	}
	else if (keycode == S_KEY)
		add_y += 1;
	else if (keycode == A_KEY)
	{
		i->player.player_dir = 2;
		add_x -= 1;
	}
	else if (keycode == ESC_KEY)
		destroy_everything(i);
	move(i, add_y, add_x);
	add_y = 0;
	add_x = 0;
	return (0);
}

int	move(t_so_info *i, int add_y, int add_x)
{
	char	element;

	element = i->arr_file[i->player.y + add_y][i->player.x + add_x];
	if (element == 'C')
		help(i, add_y, add_x, 1);
	else if (element == '0')
		help(i, add_y, add_x, 2);
	else if (element == 'E' && i->player.c_c_coin == i->c_num)
		help(i, add_y, add_x, 3);
	else if (element == 'N')
	{
		ft_printf("died\n");
		destroy_everything(i);
	}
	else if (element == 'E' || element == '1')
		return (0);
	return (0);
}
