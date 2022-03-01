/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:52:20 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 00:50:09 by elorenze         ###   ########.fr       */
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

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s1size;
	size_t	s2size;
	size_t	offset;

	offset = 0;
	s1size = ft_strnlen(s1, n);
	s2size = ft_strlen(s2);
	if (s1size < s2size)
		return (NULL);
	while (offset <= (s1size - s2size))
	{
		if (ft_memcmp(s1 + offset, s2, s2size) == 0)
			return ((char *)(s1 + offset));
		offset++;
	}
	return (NULL);
}
