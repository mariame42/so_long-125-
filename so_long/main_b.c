/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:25:36 by meid              #+#    #+#             */
/*   Updated: 2024/10/15 12:43:27 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_so_info	i;

	if (ac != 2)
	{
		perror("program has to take one parameter");
		exit(1);
	}
	i = info1(ac, av[1], 'b');
	check_the_map(&i);
	press_to_start(&i);
	free_info(&i, 3);
}
