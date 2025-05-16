/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:41:46 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/16 11:39:12 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*find_new_line(t_list *lst);
char	*dup_line(char *src);

int		get_line_len(t_list *lst);

t_list	*clean_lst(t_list **lst);
t_list	*make_list(t_list **lst, char *buff);
t_list	*new_node(char	*content);

void	get_content(t_list **lst, int fd);

#endif