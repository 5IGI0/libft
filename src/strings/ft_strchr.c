/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:36:29 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 00:35:11 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (s[0] && s[0] != (unsigned char)c)
		s++;
	if (s[0] == (unsigned char)c)
		return (s);
	return (NULL);
}
