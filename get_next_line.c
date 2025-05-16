/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:07:53 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/16 17:40:35 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	get_content(t_list **lst, int fd)//4
{
	int		read_v;
	char	*buff;

	while (!get_line_len(*lst))
	{
		buff = ft_calloc(1, BUFFER_SIZE);
		if (!buff)
			return ;
		read_v = read(fd, buff, BUFFER_SIZE);
		if (!read_v)
			return ;
		buff[read_v] = '\0';
		make_list(lst, buff);
	}
}

t_list	*clean_lst(t_list **lst)//3
{
	int		i;
	t_list	*curr;
	char	*temp;

	i = 0;
	curr = *lst;
	while (curr)
	{
		while (curr->content[i++])
		{
			if (curr->content[i -1] == '\n')
			{
				temp = dup_line(&curr->content[i]);
				free(curr->content);
				curr->content = temp;
				*lst = curr;
				return (*lst);
			}
		}
		free(curr->content);
		curr = curr->next;
	}
	return (*lst);
}

char	*find_new_line(t_list *lst)//2
{
	char		*new_line;
	t_list		*curr;
	int			index_nl;
	int			i;

	index_nl = get_line_len(lst);
	i = 0;
	curr = lst;
	new_line = ft_calloc(index_nl, sizeof(int));
	if (!new_line)
		return (NULL);
	while (curr)
	{
		while (curr->content[i - 1] != '\n' || curr->content[i] == '\0')
		{
			new_line[i] = curr->content[i];
			i++;
		}
		curr = curr->next;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)//1
{
	static t_list	*lst = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_content(&lst, fd);
	line = find_new_line(lst);
	lst = clean_lst(&lst);
	printf("%s", line);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("test_1.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return (0);
}

