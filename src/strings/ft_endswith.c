/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 01:14:40 by elorenze          #+#    #+#             */
/*   Updated: 2022/04/07 01:34:51 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_endswith(const char *str, const char *end)
{
	size_t	s;

	s = ft_strlen(end);
	return (ft_memcmp(str + ft_strlen(str) - s, end, s));
}
