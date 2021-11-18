/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilva <asilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:37:47 by asilva            #+#    #+#             */
/*   Updated: 2021/11/18 10:57:38 by asilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char *storage, char **tmp, char **buff)
{
	int		i;
	int		j;
	int		lbuff;
	char	*line;

	i = 0;
	while ((*tmp)[i] != '\n')
		i++;
	i++;
	lbuff = ft_strlen(*buff);
	line = malloc(sizeof(char) * i + lbuff + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, *buff, lbuff);
	ft_memcpy(line + lbuff, *tmp, i);
	line[lbuff + i] = '\0';
	j = 0;
	while ((*tmp)[i] != '\0')
		storage[j++] = (*tmp)[i++];
	storage[j] = '\0';
	free (*buff);
	*buff = NULL;
	return (line);
}

static char	*read_line(int fd, char *storage, char **tmp, char **buff)
{
	ssize_t	rd;
	char	*ptr;

	ptr = 0;
	while (!ptr)
	{
		rd = read(fd, *tmp, BUFFER_SIZE);
		if (rd < 0)
			return (NULL);
		if (rd == 0)
		{
			ptr = *buff;
			return (ptr);
		}
		(*tmp)[rd] = '\0';
		if (ft_strchr(*tmp, '\n'))
			return (get_line(storage, tmp, buff));
		ptr = *buff;
		*buff = ft_strjoin(*buff, *tmp);
		if (ptr)
			free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

static char	*new_line(char **line, char *storage)
{
	int	i;
	int	j;

	i = 0;
	while (storage[i] != '\n')
		i++;
	i++;
	*line = malloc(sizeof(char) * i + 1);
	if (!line && !*line)
		return (NULL);
	ft_memcpy(*line, storage, i);
	(*line)[i] = '\0';
	j = 0;
	while (storage[i] != '\0')
		storage[j++] = storage[i++];
	storage[j] = '\0';
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	storage[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	char		*buff;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	if (ft_strchr(storage[fd], '\n'))
		return (new_line(&line, storage[fd]));
	buff = ft_strdup(storage[fd]);
	if (!buff && ft_strlen(storage[fd]) != 0)
		return (NULL);
	storage[fd][0] = '\0';
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	line = read_line(fd, storage[fd], &tmp, &buff);
	free(tmp);
	return (line);
}
