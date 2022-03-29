/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:35:11 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/29 07:57:13 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include "../../libft.h"

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strnlen(s, start + len);
	if (slen <= start)
		slen = start;
	slen -= start;
	ret = malloc(slen + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s + start, slen);
	ret[slen] = 0;
	return (ret);
}
