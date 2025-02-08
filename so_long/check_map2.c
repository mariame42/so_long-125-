/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:07:10 by meid              #+#    #+#             */
/*   Updated: 2024/10/18 08:05:50 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_new_line(t_so_info *i)
{
	t_list	*last_node;
	char	*str;
	char	*new_str;

	last_node = ftt_lstlast(i->file_l);
	str = last_node->con;
	if (str[ftt_strlen(str) - 1] != '\n')
	{
		new_str = ft_strjoin(str, "\n");
		free(last_node->con);
		last_node->con = new_str;
	}
}

char	**list_to_array(t_so_info *i)
{
	int		len;
	t_list	*tmp;
	int		j;

	len = ftt_lstsize(i->file_l);
	i->arr_file = malloc(sizeof(char *) * (len + 1));
	if (!i->arr_file)
		return (NULL);
	tmp = i->file_l;
	j = 0;
	while (tmp)
	{
		i->arr_file[j] = ftt_strdup_rm_n(tmp->con);
		tmp = tmp->next;
		j++;
	}
	return (i->arr_file[j] = NULL, i->arr_file);
}

void	rectangular_check(t_so_info *i)
{
	int		len;
	t_list	*tmp;
	int		l;

	player_pos(i);
	len = ftt_strlen(i->file_l->con);
	tmp = i->file_l;
	while (tmp->next->next)
	{
		if (tmp->len != tmp->next->len)
			handle_error("1: this is  not a rectangular shape", i, 2);
		tmp = tmp->next;
	}
	l = tmp->len;
	if (len != l)
		handle_error("2: this is  not a rectangular shape", i, 2);
}

void	call_path(t_so_info *i)
{
	check_path(i);
	i->flag.p_num = 2;
	check_path(i);
	if (i->flag.part == 'b')
	{
		i->flag.p_num = 3;
		check_path(i);
	}
}

void	check_path(t_so_info *i)
{
	t_point	size;
	char	**zone;
	char	**area;
	t_point	begin;
	int		j;

	size = (t_point){i->win.width + 1, i->win.height};
	zone = i->arr_file;
	area = make_area(zone, size);
	begin = (t_point){i->player.x, i->player.y};
	flood_fill(area, size, begin);
	i->path_check = malloc(sizeof(char *) * (i->win.height + 1));
	j = -1;
	while (++j < i->win.height)
		i->path_check[j] = ftt_strdup(area[j]);
	i->path_check[j] = NULL;
	if (((i->flag.p_num == 1 || i->flag.p_num == 3)
			&& check_how_many('E', i, 2) > 0)
		|| check_how_many('C', i, 2) > 0 || check_how_many('P', i, 2) > 0)
		handle_error("this is a bad path : (", i, 3);
	free_array(area, i->win.height);
	check_for_extra_element(i);
	return ;
}
