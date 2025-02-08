/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:46:43 by meid              #+#    #+#             */
/*   Updated: 2024/10/13 17:13:12 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_list(int fd)
{
	char	*cur;
	t_list	*all;
	t_info	i;

	i = (t_info){0};
	cur = get_next_line(fd, &i);
	if (!cur)
	{
		free(cur);
		return (NULL);
	}
	all = ftt_lstnew(ftt_strdup(cur));
	free(cur);
	while_loop(&i, cur, all, fd);
	return (all);
}

void	while_loop(t_info *i, char *cur, t_list *all, int fd)
{
	t_list	*c;

	while (1)
	{
		cur = get_next_line(fd, i);
		if (!cur)
		{
			free(cur);
			break ;
		}
		c = ftt_lstnew(ftt_strdup(cur));
		ftt_lstadd_back(&all, c);
		free(cur);
	}
}
