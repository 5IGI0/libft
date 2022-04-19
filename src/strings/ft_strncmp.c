/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:44:50 by elorenze          #+#    #+#             */
/*   Updated: 2022/04/19 08:01:26 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (s1 == NULL || s2 == NULL)
	{
		if (s1 < s2)
			return (-256);
		else if (s2 < s1)
			return (256);
		return (0);
	}
	n--;
	while (n && s1[0] && s1[0] == s2[0])
	{
		s1++;
		s2++;
		n--;
	}
	return ((int)s1[0] - (int)s2[0]);
}
