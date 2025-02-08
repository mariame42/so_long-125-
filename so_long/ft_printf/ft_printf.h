/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:18:26 by meid              #+#    #+#             */
/*   Updated: 2024/07/23 08:18:28 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

ssize_t	put_nbr(long nb);
ssize_t	put_char(char c);
ssize_t	put_str(char *str);
ssize_t	put_hex(unsigned long nb, char up_low);
ssize_t	put_ptr(char *str);
int		ft_printf(const char *str, ...);

#endif
