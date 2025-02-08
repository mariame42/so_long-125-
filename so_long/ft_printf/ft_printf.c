/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:18:33 by meid              #+#    #+#             */
/*   Updated: 2024/07/23 18:22:52 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cons(char type, va_list arg)
{
	if (type == 'c')
		return (put_char(va_arg(arg, int)));
	else if (type == 's')
		return (put_str(va_arg(arg, char *)));
	else if (type == 'p')
		return (put_ptr(va_arg(arg, void *)));
	else if (type == 'd' || type == 'i')
		return (put_nbr(va_arg(arg, int)));
	else if (type == 'u')
		return (put_nbr(va_arg(arg, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (put_hex(va_arg(arg, unsigned int), type));
	else if (type == '%')
		return (put_char('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;
	int		tmp;

	va_start(arg, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			tmp = cons(*(++str), arg);
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		else
		{
			if (put_char(*str) == -1)
				return (-1);
			len++;
		}
		str++;
	}
	va_end(arg);
	return (len);
}
