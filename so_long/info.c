/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:17:59 by meid              #+#    #+#             */
/*   Updated: 2024/10/18 07:12:49 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_so_info	info1(int ac, char *file_name, char flag)
{
	t_so_info	i;

	(void)ac;
	i.map_loc = ft_strjoin("maps/", file_name);
	i.file_l = NULL;
	i.arr_file = NULL;
	i.path_check = NULL;
	i.x = 0;
	i.y = 0;
	i.player.player_dir = 1;
	i.player.c_c_coin = 0;
	i.player.moves = 0;
	i.player.y = 0;
	i.player.x = 0;
	i.enemy_x = 0;
	i.enemy_y = 0;
	i.index = 0;
	i.flag.p_num = 1;
	i.flag.part = flag;
	i.numstr2 = NULL;
	i.numstr = NULL;
	return (i);
}

void	free_info(t_so_info *i, int flag)
{
	free(i->map_loc);
	i->map_loc = NULL;
	if (flag >= 2)
		ftt_lstclear(&i->file_l);
	if (flag >= 3)
	{
		free_array(i->path_check, 0);
		free_array(i->arr_file, 0);
	}
}
