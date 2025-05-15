/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:07:53 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/15 21:59:51 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	get_content(t_list **lst, int fd)
{
	int		read_v;
	char	*buff;

	while (!get_line_len(*lst))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return ;
		read_v = read(fd, buff, BUFFER_SIZE);
		if (!read_v)
			return ;
		buff[read_v] = '\0';
		make_list(lst, buff);
	}
}

void	clean_lst(t_list **lst)
{
	int	i;
	
}

char	*find_new_line(t_list *lst)
{
	char		*new_line;
	t_list		*temp;
	int			index_nl;
	int			i;

	index_nl = get_line_len(lst);
	i = 0;
	temp = lst;
	new_line = (char *)malloc(index_nl + 1);
	if (!new_line)
		return (NULL);
	while (temp && i <= index_nl)
	{
		while (temp->content[i -1] != '\n' || temp->content[i] == '\0')
		{
			new_line[i] = temp->content[i];
			i++;
		}
		temp = temp->next;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char	*line;

	lst = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_content(&lst, fd);
	line = find_new_line(lst);
	//clear lst
	printf("%s", line);
	return (line);
}

int	main()
{
	int	fd;

	fd = open("test_1.txt", O_RDONLY);
	get_next_line(fd);

	return (0);
}
