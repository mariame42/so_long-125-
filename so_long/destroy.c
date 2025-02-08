/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:33:09 by meid              #+#    #+#             */
/*   Updated: 2024/10/15 12:49:28 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_everything(t_so_info *i)
{
	int	j;
	int	k;

	if (i->flag.part == 'm')
		k = 6;
	if (i->flag.part == 'b')
		k = 13;
	j = 0;
	while (j < k)
	{
		if (i->imges[j].img == NULL)
		{
			j++;
			continue ;
		}
		mlx_destroy_image(i->mlx, i->imges[j].img);
		j++;
	}
	mlx_destroy_window(i->mlx, i->win.mlx_win);
	handle_error("destroy_everything : done", i, 4);
	return (1);
}
