/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:40:52 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/12 19:09:24 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line(int fd)
{
	int		fd;
	char	buff[BUFFER_SIZE];
	int		read_v;
	int		count;

	fd = open("test_1.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	read_v = read(fd, buff, BUFFER_SIZE);
}