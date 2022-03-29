/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:47:17 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 00:29:41 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t	offset;

	if (dest == NULL || src == NULL)
		return (NULL);
	if (dest < src)
	{
		offset = 0;
		while (offset < n)
		{
			((unsigned char *)dest)[offset] = ((unsigned char *)src)[offset];
			offset++;
		}
	}
	else
	{
		while (n)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}
