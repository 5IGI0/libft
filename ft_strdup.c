/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:11:04 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 00:26:21 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*str;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s) + 1;
	str = malloc(slen);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, slen);
	return (str);
}
