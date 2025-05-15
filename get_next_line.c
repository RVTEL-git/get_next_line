/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:07:53 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/15 15:08:31 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/*
- Dois-je toujours iterrer sur temp/curr pour lst ?
*/

#include "get_next_line.h"
#include <stdio.h>

int	get_line(t_list *lst)
{
	int	i;

	i = 0;
	printf("3 - get_line\n");
	while (lst)
	{
		while (lst->content[i] && i < BUFFER_SIZE)
		{
			if (lst->content[i] == '\n')
				return (i);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

void	make_list(t_list **lst, char *buff)
{
	t_list	*node;

	printf("4 - make_list\n");
	node = ft_lstnew(buff);
	ft_lstadd_back(lst, node);
}

void	get_content(t_list **lst, int fd)
{
	int		read_v;
	char	*buff;

	printf("2 - get_content\n");
	while (!get_line(*lst))
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

char	*find_new_line(t_list *lst)
{
	char	*new_line;
	char	*temp_str;
	t_list	*temp_lst;
	int		index_nl;
	int		i;

	index_nl = get_line(lst);
	temp_lst = lst;
	i = 0;
	while (temp_lst)
	{
		while (temp_lst->content[i -1] != '\n')
		{
			if (temp_lst->content[i] == '\0' || temp_lst->content[i] == '\n')
			{
				new_line = join(new_line, temp_lst->content);
				temp_lst = temp_lst->next;
			}
			i++;
		}
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	t_list	*lst;
	char	*line;

	printf("1 - get_next_line\n");
	lst = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_content(&lst, fd);
	line = find_new_line(lst);
	return (line);
}

int	main()
{
	int	fd;

	fd = open("test_1.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
