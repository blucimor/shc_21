/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucimor <blucimor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:25:49 by blucimor          #+#    #+#             */
/*   Updated: 2021/05/10 17:42:49 by blucimor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_last_line(char **last_line, char **line)
{
	char	*pointer;

	pointer = NULL;
	if (!(*last_line))
	{
		*line = malloc(1);
		**line = '\0';
	}
	else
	{
		pointer = ft_strchr(*last_line, '\n');
		if (pointer)
		{
			*pointer = '\0';
			*line = ft_strdup(*last_line);
			ft_strcpy(*last_line, ++pointer);
		}
		else
		{
			*line = ft_strdup(*last_line);
			free(*last_line);
			*last_line = NULL;
		}
	}
	return (pointer);
}

static char	*ft_find_last_line(char **pointer, char *buf)
{
	char	*last_line;

	last_line = NULL;
	*pointer = ft_strchr(buf, '\n');
	if (*pointer)
	{
		**pointer = '\0';
		last_line = ft_strdup(++(*pointer));
	}
	return (last_line);
}

static void	ft_norma_besit(char	**buf, int *res)
{
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	*res = 1;
}

int	get_next_line(int fd, char **line)
{
	static char	*last_line;
	char		*buf;
	char		*pointer;
	char		*leak;
	int			res;

	ft_norma_besit(&buf, &res);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0 || !line || !buf)
		return (-1);
	pointer = check_last_line(&last_line, line);
	while (!pointer && res)
	{
		res = read(fd, buf, BUFFER_SIZE);
		buf[res] = '\0';
		last_line = ft_find_last_line(&pointer, buf);
		leak = *line;
		*line = ft_strjoin(*line, buf);
		if (!(*line))
			return (-1);
		free(leak);
	}
	free(buf);
	if (res == 0 && !last_line)
		return (0);
	return (1);
}
