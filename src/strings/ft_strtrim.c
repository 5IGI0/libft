/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:02:12 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/29 07:57:13 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include "../../libft.h"

static int	is_in_charset(char c, const char *set)
{
	while (set[0])
	{
		if (c == set[0])
			return (1);
		set++;
	}
	return (0);
}

static const char	*get_size(const char *str, const char *set, size_t *size)
{
	const char	*start;

	while (is_in_charset(str[0], set))
		str++;
	start = str;
	if (str[0] == 0)
	{
		size[0] = 0;
		return (str);
	}
	while (str[0])
		str++;
	str--;
	while (is_in_charset(str[0], set))
		str--;
	size[0] = (str - start) + 1;
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	alloc_size;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	s1 = get_size(s1, set, &alloc_size);
	ret = malloc(alloc_size + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, alloc_size);
	ret[alloc_size] = 0;
	return (ret);
}
