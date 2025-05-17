/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:41:46 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/17 15:59:40 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);//1
char	*make_new_line(t_list *lst, int i);
char	*dup_line(char *src);//3

int		get_line_len(t_list *lst);//4

t_list	*clean_lst(t_list **lst);//5
t_list	*make_list(t_list **lst, char *buff);//6
t_list	*new_node(char	*content);

void	get_content(t_list **lst, int fd);//7
void	print_list(t_list *lst);//8

#endif