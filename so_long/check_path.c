/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:41:09 by meid              #+#    #+#             */
/*   Updated: 2024/10/18 08:06:02 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill3(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == '1'
		|| tab[cur.y][cur.x] == 'N' || tab[cur.y][cur.x] == to_fill)
		return ;
	tab[cur.y][cur.x] = to_fill;
	fill3(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill3(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill3(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill3(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	fill2(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'E'
		|| tab[cur.y][cur.x] == to_fill)
		return ;
	tab[cur.y][cur.x] = to_fill;
	fill2(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill2(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill2(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill2(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == to_fill)
		return ;
	tab[cur.y][cur.x] = to_fill;
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	static int	i;

	if (i == 0)
	{
		fill(tab, size, begin, 32);
		i++;
	}
	else if (i == 1)
	{
		fill2(tab, size, begin, 32);
		i++;
	}
	else if (i == 2)
	{
		fill3(tab, size, begin, 32);
	}
}

char	**make_area(char **zone, t_point size)
{
	char	**new;
	int		i;
	int		j;

	new = malloc(sizeof(char *) * (size.y + 1));
	i = 0;
	while (i < size.y)
	{
		new[i] = malloc(size.x + 1);
		j = 0;
		while (j < size.x)
		{
			new[i][j] = zone[i][j];
			j++;
		}
		new[i][size.x] = '\0';
		i++;
	}
	return (new);
}
