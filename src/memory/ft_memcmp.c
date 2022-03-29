/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:58:34 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 00:29:37 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	if (n == 0 || s1 == NULL || s2 == NULL)
		return (0);
	n--;
	while (n && ((unsigned char *)s1)[0] == ((unsigned char *)s2)[0])
	{
		n--;
		s1++;
		s2++;
	}
	return (
		(int)(((unsigned char *)s1)[0])
		-
		(int)(((unsigned char *)s2)[0])
	);
}
