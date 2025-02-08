/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:20:26 by meid              #+#    #+#             */
/*   Updated: 2024/10/18 08:05:28 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_the_map(t_so_info *i)
{
	int	fd;

	fd = open(i->map_loc, O_RDONLY);
	if (fd == -1)
		handle_error("there_is_not_a_file_called_that", i, 1);
	i->file_l = get_list(fd);
	if (!i->file_l)
	{
		close(fd);
		handle_error("the folder is empty", i, 2);
	}
	i->win.height = ftt_lstsize(i->file_l);
	if (i->win.height < 3 || i->win.height > 29)
		handle_error("the map is so small or so big(height)", i, 2);
	add_new_line(i);
	map_check(i->file_l, i);
	check_elements(i);
	rectangular_check(i);
	i->win.width = ftt_strlen(i->file_l->con) - 1;
	if (i->win.width < 3 || i->win.width > 53)
		handle_error("the map is so small or so big(width)", i, 2);
	call_path(i);
	ft_printf("the file is there and walls are good\n");
}

void	map_check(t_list *list, t_so_info *i)
{
	t_list	*tmp;

	list_to_array(i);
	tmp = list;
	if (tmp)
	{
		check(tmp->con, "all", '1', i);
		tmp = tmp->next;
	}
	while (tmp->next)
	{
		check(tmp->con, "first_and_last", '1', i);
		tmp = tmp->next;
	}
	if (tmp)
	{
		check(tmp->con, "all", '1', i);
		tmp = tmp->next;
	}
	return ;
}

void	check(char *con, char *part_to_check, char char_to_check, t_so_info *i)
{
	int	j;

	j = 0;
	if (ftt_strcmp(part_to_check, "all") == 0)
	{
		while (con[j] && con[j] != '\n')
		{
			if (con[j] != char_to_check)
			{
				handle_error("first and last row should be a wall", i, 2);
			}
			j++;
		}
		return ;
	}
	else if (ftt_strcmp(part_to_check, "first_and_last") == 0)
	{
		if (con[0] != char_to_check && con[j] != '\n')
			handle_error("the right side should have a wall", i, 2);
		if (con[ftt_strlen(con) - 2] != char_to_check)
			handle_error("the left side should have a wall", i, 2);
		return ;
	}
	return ;
}

void	check_elements(t_so_info *i)
{
	if (check_how_many('P', i, 1) != 1)
		handle_error("the number of player is not true", i, 2);
	if (check_how_many('E', i, 1) != 1)
		handle_error("the number of exits is not true", i, 2);
	i->c_num = check_how_many('C', i, 1);
	if (i->c_num < 1)
		handle_error("at lest one collectible", i, 2);
}

int	check_how_many(char check_char, t_so_info *i, int flag)
{
	t_list	*tmp;
	int		count;
	int		j;

	count = 0;
	j = 0;
	if (flag == 1)
	{
		tmp = i->file_l;
		while (tmp)
		{
			count += ft_strchr_num(tmp->con, check_char);
			tmp = tmp->next;
		}
	}
	else if (flag == 2)
	{
		while (i->path_check[j])
		{
			count += ft_strchr_num(i->path_check[j], check_char);
			j++;
		}
	}
	return (count);
}
