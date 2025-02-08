/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:18:43 by meid              #+#    #+#             */
/*   Updated: 2024/07/23 17:47:00 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	put_char(char c)
{
	return (write(1, &c, 1));
}

ssize_t	put_nbr(long nb)
{
	ssize_t	len;
	ssize_t	tmp;

	len = 0;
	if (nb < 0)
	{
		if (put_char('-') == -1)
			return (-1);
		len += 1;
		nb *= -1;
	}
	if (nb > 9)
	{
		tmp = put_nbr (nb / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &("0123456789")[nb % 10], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

ssize_t	put_str(char *str)
{
	ssize_t	i;
	ssize_t	len;

	i = 0;
	len = 0;
	while (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (put_char(str[i]) == -1)
			return (-1);
		i++;
		len++;
	}
	return (len);
}

ssize_t	put_hex(unsigned long nb, char up_low)
{
	unsigned long	len;
	ssize_t			tmp;
	char			*arr;

	len = 0;
	tmp = 0;
	if (up_low == 'X')
		arr = "0123456789ABCDEF";
	else
		arr = "0123456789abcdef";
	if (nb > 15)
	{
		tmp = put_hex((nb / 16), up_low);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &arr[nb % 16], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

ssize_t	put_ptr(char *str)
{
	ssize_t	len;
	ssize_t	tmp;

	len = 0;
	tmp = 0;
	if (put_str("0x") == -1)
		return (-1);
	len += 2;
	tmp = put_hex((unsigned long)str, 'x');
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}
