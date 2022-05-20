/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:24:53 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/20 15:10:56 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include <unistd.h>

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

static void	gnl_clear(char *buffer, int i)
{
	int	y;

	y = 0;
	while (y < BUFFER_SIZE)
	{
		if (y + i > BUFFER_SIZE)
			buffer[y] = 0;
		else
			buffer[y] = buffer[y + i];
		y++;
	}
}

static int	gnl_on_read_free_and_return(int ret, char **line)
{
	free(line[0]);
	line[0] = NULL;
	return (ret);
}

static int	gnl_on_read(char *buffer, char **line, int forceret)
{
	int		i;
	char	tmp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	tmp = buffer[i];
	buffer[i] = 0;
	if (gnl_append(line, buffer) < 0)
		return (gnl_on_read_free_and_return(-1, line));
	buffer[i] = tmp;
	if (i != 0)
		tmp = buffer[i - 1];
	gnl_clear(buffer, i);
	if (tmp == '\n' || forceret)
	{
		if (line[0][0] == 0)
			return (gnl_on_read_free_and_return(1, line));
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "";
	ssize_t		rret;
	char		*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	rret = BUFFER_SIZE;
	while (gnl_on_read(buffer, &line, rret < 1) == 0)
	{
		rret = read(fd, buffer, BUFFER_SIZE);
		if (rret < 0)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}
