/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:57:56 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/04 19:01:19 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

size_t	gnl_strlen(char *str)
{
	char	*strt;

	if (str == NULL)
		return (0);
	strt = str;
	while (str[0])
		str++;
	return (str - strt);
}

char	*gnl_strcat(char *dest, char *src)
{
	char	*strt;

	if (src == NULL)
		return (NULL);
	strt = dest;
	while (dest[0])
		dest++;
	while (src[0])
	{
		dest[0] = src[0];
		dest++;
		src++;
	}
	dest[0] = '\0';
	return (strt);
}

int	gnl_append(char **dest, char *src)
{
	char	*tmp;

	tmp = malloc(gnl_strlen(src) + gnl_strlen(dest[0]) + 1);
	if (tmp == NULL)
		return (-1);
	tmp[0] = 0;
	gnl_strcat(tmp, dest[0]);
	gnl_strcat(tmp, src);
	free(dest[0]);
	dest[0] = tmp;
	return (0);
}
