/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:07:53 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/17 17:19:33 by barmarti         ###   ########.fr       */
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
		{
			free(buff);
			return ;
		}
		buff[read_v] = '\0';
		make_list(lst, buff);
	}
}

t_list	*clean_lst(t_list **lst)
{
	int		i;
	t_list	*curr;
	t_list	*to_free;
	char	*temp;

	curr = *lst;
	while (curr)
	{
		i = 0;
		while (curr->content[i])
		{
			if (curr->content[i] == '\n')
			{
				temp = dup_line(&curr->content[i + 1]);
				free(curr->content);
				curr->content = temp;
				*lst = curr;
				return (*lst);
			}
			i++;
		}
		to_free = curr;
		curr = curr->next;
		free(to_free->content);
		free(to_free);
	}
	return (*lst);
}

char	*make_new_line(t_list *lst, int len)
{
	char		*new_line;
	t_list		*curr;
	int			i;
	int			j;

	curr = lst;
	j = 0;
	new_line = malloc((sizeof(char) * len) + 1);
	if (!new_line)
		return (NULL);
	while (curr)
	{
		i = 0;
		while (curr->content[i] && curr->content[i] != '\n')
			new_line[j++] = curr->content[i++];
		if (curr->content[i] == '\n')
		{
			new_line[j++] = '\n';
			break ;
		}
		curr = curr->next;
	}
	new_line[j++] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;
	int				index_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_content(&lst, fd);
	index_nl = get_line_len(lst);
	line = make_new_line(lst, index_nl);
	lst = clean_lst(&lst);
	if (lst == NULL)
		return (NULL);
	printf("%s", line);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("test_1.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
