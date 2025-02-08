/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:21:52 by meid              #+#    #+#             */
/*   Updated: 2024/10/13 16:23:46 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(t_so_info *i)
{
	t_list	*tmp;
	int		x_pos;

	tmp = i->file_l;
	x_pos = 0;
	while (tmp)
	{
		x_pos = ft_strchr_pos(tmp->con, 'P');
		if (x_pos >= 0)
		{
			i->player.x = x_pos;
			return ;
		}
		tmp = tmp->next;
		i->player.y += 1;
	}
	return ;
}

int	ft_strchr_pos(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	check_for_extra_element(t_so_info *i)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	y = 0;
	while (i->arr_file[x])
	{
		y = 0;
		while (i->arr_file[x][y])
		{
			c = i->arr_file[x][y];
			if (i->flag.part == 'm' && c != '1' && c != 'P' && c != '0'
				&& c != 'E' && c != 'C')
				handle_error("extra element in man", i, 3);
			else if (i->flag.part == 'b' && c != '1' && c != 'P' && c != '0'
				&& c != 'E' && c != 'C' && c != 'N')
				handle_error("extra element in bouns", i, 3);
			y++;
		}
		x++;
	}
}
