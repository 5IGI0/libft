/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 01:14:40 by elorenze          #+#    #+#             */
/*   Updated: 2022/04/13 10:25:34 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_endswith(const char *str, const char *end)
{
	size_t	s;
	size_t	e;

	e = ft_strlen(end);
	s = ft_strlen(str);
	if (e > s)
		return (-1);
	return (ft_memcmp(str + s - e, end, s));
}
