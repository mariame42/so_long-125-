/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:11:02 by meid              #+#    #+#             */
/*   Updated: 2024/10/18 07:52:18 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(ftt_strlen(s1) + ftt_strlen(s2) + 1);
	if (!(str))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

int	ft_strchr_num(char *str, char search_for)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == search_for)
			count++;
		i++;
	}
	return (count);
}

char	*ftt_strdup_rm_n(char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(*s1) * (ftt_strlen(s1)));
	if (!str)
		return (NULL);
	while (s1[i] && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	free_array(char **array, int flag)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	if (flag == 0)
	{
		while (array[i] != NULL)
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
	}
	else
	{
		while (i < flag)
		{
			free(array[i]);
			i++;
		}
	}
	free(array);
	return (array = NULL, 0);
}

int	ftt_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		++counter;
		lst = lst->next;
	}
	return (counter);
}
