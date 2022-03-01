/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:52:50 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 00:29:33 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(void *s, int c, size_t n)
{
	if (n == 0 || s == NULL)
		return (NULL);
	while (n && ((unsigned char *)s)[0] != (unsigned char)c)
	{
		n--;
		s++;
	}
	if (((unsigned char *)s)[0] == (unsigned char)c)
		return (s);
	return (NULL);
}
