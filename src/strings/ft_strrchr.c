/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:38:51 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 00:49:40 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(char *s, int c)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = s;
	while (ptr[0])
		ptr++;
	while (ptr > s && ptr[0] != (unsigned char)c)
		ptr--;
	if (ptr[0] == (unsigned char)c)
		return (ptr);
	return (NULL);
}
