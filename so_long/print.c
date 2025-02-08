/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:09:24 by meid              #+#    #+#             */
/*   Updated: 2024/10/18 07:52:40 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_error(char *msg, t_so_info *i, int flag)
{
	ft_printf("%s\n", msg);
	free_info(i, flag);
	if (flag == 4)
		exit(0);
	exit(1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		temp;

	len = 0;
	temp = n;
	if (n == 0)
		return ("0");
	while (temp && ++len)
		temp /= 10;
	str = (char *)malloc(len + 1);
	str[len] = '\0';
	while (n)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
