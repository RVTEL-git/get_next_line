/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:41:46 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/22 09:48:52 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char		*get_next_line(int fd);
char		*make_new_line(t_list *lst, int i);
char		*dup_line(char *src);

int			is_nl(t_list *lst);
int			get_len(t_list *lst);

void		free_lst(t_list **list, t_list *new_node, char *rest);
t_list		*make_list(t_list **lst, char *buff);
t_list		*new_node(char	*content);

void		get_content(t_list **lst, int fd);
void		clean_lst(t_list **list);

#endif