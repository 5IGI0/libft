/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:36:42 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/29 07:57:13 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	offset;

	if (s == NULL)
		return (NULL);
	ret = malloc(ft_strlen(s) + 1);
	if (ret == NULL)
		return (NULL);
	offset = 0;
	while (s[offset])
	{
		if (f)
			ret[offset] = f(offset, s[offset]);
		else
			ret[offset] = s[offset];
		offset++;
	}
	ret[offset] = 0;
	return (ret);
}
