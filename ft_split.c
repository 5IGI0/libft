/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 00:28:20 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/22 15:02:11 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include "libft.h"

static size_t	count_segment(const char *s, char c)
{
	size_t	ret;

	ret = 1;
	while (s[0] && s[0] == c)
		s++;
	if (s[0] == 0)
		return (0);
	while (s[0])
	{
		if (s[0] == c)
		{
			if (s[-1] != c)
				ret++;
		}
		s++;
	}
	if (s[-1] == c)
		ret--;
	return (ret);
}

static const char	*strskip(const char *s, char c)
{
	while (s[0] && s[0] == c)
		s++;
	return (s);
}

static size_t	count_until_delim(const char *s, char c)
{
	const char	*start;

	start = s;
	while (s[0] && s[0] != c)
		s++;
	return (s - start);
}

static char	**fast_exit(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	cursegsize;
	char	**ret;

	if (s == NULL)
		return (NULL);
	i = 0;
	ret = ft_calloc(count_segment(s, c) + 1, sizeof(char *));
	if (ret == NULL)
		return (NULL);
	s = strskip(s, c);
	while (s[0])
	{
		cursegsize = count_until_delim(s, c);
		ret[i] = malloc(cursegsize + 1);
		if (ret[i] == NULL)
			return (fast_exit(ret));
		ft_memcpy(ret[i], s, cursegsize);
		ret[i][cursegsize] = 0;
		s += cursegsize;
		s = strskip(s, c);
		i++;
	}
	return (ret);
}
