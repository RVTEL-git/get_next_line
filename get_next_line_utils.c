/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:41:48 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/16 13:14:57 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	print_list(t_list *lst)
{
	if (!lst)
	{
		printf("No list available\n");
		return ;
	}
	while (lst)
	{
		printf(" [%s] -> ", lst->content);
		lst = lst->next;
	}
}

t_list	*new_node(char	*content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*make_list(t_list **lst, char *buff)
{
	t_list	*curr;
	t_list	*new;

	if (!lst || !buff)
		return (NULL);
	new = new_node(buff);
	if (!*lst)
	{
		*lst = new;
		return (*lst);
	}
	curr = *lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	return (*lst);
}

int	get_line_len(t_list *lst)
{
	int		i;
	int		j;
	t_list	*curr;

	curr = lst;
	i = 0;
	j = 0;
	while (curr)
	{
		j = 0;
		while (curr->content[j])
		{
			if (curr->content[j] == '\n')
			{
				i++;
				j++;
				return (i);
			}
			i++;
			j++;
		}
		curr = curr->next;
	}
	return (0);
}

char	*dup_line(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dup = malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}