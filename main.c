/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:55:31 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/14 19:07:01 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_putstr("Err || check args");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	else if (fd < 0)
	{
		ft_putstr("Err || can't open file");
		get_next_line(av[1]);
		return (1);
	}
	else
	{
		get_next_line(av[1]);
		return (0);
	}
}
