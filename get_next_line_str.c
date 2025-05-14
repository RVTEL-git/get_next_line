/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:40:52 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/13 17:56:50 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t elem_c, size_t elem_s)
{
	size_t			i;
	size_t			total;
	unsigned char	*dest;

	i = 0;
	if (elem_s != 0 && elem_c > (size_t)-1 / elem_s)
		return (NULL);
	total = elem_c * elem_s;
	dest = (unsigned char *)malloc(total);
	if (!dest)
		return (NULL);
	while (i < total)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	unsigned int	i;
	char			*join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	i = -1;
	join = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!join)
		return (NULL);
	while (s1[++i])
		join[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		join[s1_len] = s2[i];
		s1_len++;
	}
	join[s1_len] = '\0';
	return (join);
}

int	find_line(char *buff)
{
	int	index;
	int	start;
	int	count;

	index = 0;
	start = 0;
	count = 0;
	while (buff[index])
	{
		if (buff[index] == '\n' || buff[index + 1] == '\0')
		{
			return (index);
		}
		index++;
	}
	return (index);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*stash;
	int			read_v;
	int			index;

	/*
	calloc stash elem_c = ???
	ft_strjoin buffer + stash ???
	Comment utiliser les index de lignes ?
	BUFFER_SIZE -n a voir
	*/
	stash = ft_calloc(1, sizeof(char));
	if (fd == -1)
		return (NULL);
	read_v = -1;
	index = 0;
	while (read_v != 0)
	{
		read_v = read(fd, buff, BUFFER_SIZE);
		if (read_v < 0)
			return (NULL);
		if (find_line(buff) > 0)
			stash = ft_strjoin(stash, buff);
	}
	close(fd);
	printf("%s", stash);
	return (stash);
}

int	main(void)
{
	int	fd;

	fd = open("test_1.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
