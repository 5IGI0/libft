/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:57:28 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 14:53:53 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1size;
	size_t	s2size;
	char	*ret;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	ret = malloc(s1size + s2size + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, s1size);
	ft_memcpy(ret + s1size, s2, s2size);
	ret[s1size + s2size] = 0;
	return (ret);
}
