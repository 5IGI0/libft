/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:12:26 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 00:46:11 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	size;

	if (maxlen == 0)
		return (0);
	size = 0;
	while (size < maxlen && s[size])
		size++;
	return (size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	left_space;
	char	*ret;

	if (dst == NULL || src == NULL)
		return (ft_strnlen(dst, size) + ft_strlen(src));
	ret = dst;
	left_space = size;
	while (left_space && dst[0])
	{
		dst++;
		left_space--;
	}
	if (left_space == 0)
		return (size + ft_strlen(src));
	left_space--;
	while (left_space && src[0])
	{
		dst[0] = src[0];
		dst++;
		src++;
		left_space--;
	}
	dst[0] = 0;
	return (ft_strlen(ret) + ft_strlen(src));
}
