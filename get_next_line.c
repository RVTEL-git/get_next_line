/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:07:53 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/16 12:09:48 by barmarti         ###   ########.fr       */
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

t_list	*clean_lst(t_list **lst)
{
	int		i;
	t_list	*new;
	t_list	*curr;
	char	*temp;

	i = 0;
	curr = *lst;
	while (*lst)
	{
		while (lst->content[i++])
		{
			if (curr->content[i -1] == '\n')
			{
				temp = dup_line(&curr->content[i]);
				free(curr->content);
				new = new_node(temp);
				new->content = temp;
				new->next = *lst;
				return (*lst);
			}
		}
		free(curr->content);
		curr = curr->next;
	}
	return (*lst);
}

char	*find_new_line(t_list *lst)
{
	char		*new_line;
	t_list		*curr;
	int			index_nl;
	int			i;

	index_nl = get_line_len(lst);
	i = 0;
	curr = lst;
	new_line = (char *)malloc(index_nl + 1);
	if (!new_line)
		return (NULL);
	while (curr && i <= index_nl)
	{
		while (curr->content[i -1] != '\n' || curr->content[i] == '\0')
		{
			new_line[i] = curr->content[i];
			i++;
		}
		curr = curr->next;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_content(&lst, fd);
	line = find_new_line(lst);
	clean_lst(&lst);
	printf("%s", line);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("test_1.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	return (0);
}
