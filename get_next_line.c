/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:07:53 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/15 11:11:10 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_content(t_list **lst, int fd)
{
	int		read_v;
	char	*buff;

	while (!get_line(lst))
	{
		while (read_v = read(fd, buff, BUFFER_SIZE))
		if (!read_v)
			return (NULL);
		
	}

}

char	*get_next_line(int fd)
{
	t_list	*lst;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_content(&lst, fd);
	return (line);
}
