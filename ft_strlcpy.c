/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:00:08 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 00:47:44 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	offset;

	if (src == NULL || dst == NULL)
		return (ft_strlen(src));
	if (size != 0)
	{
		size--;
		offset = 0;
		while (offset < size && src[offset])
		{
			dst[offset] = src[offset];
			offset++;
		}
		dst[offset] = 0;
	}
	return (ft_strlen(src));
}
