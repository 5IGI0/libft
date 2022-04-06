/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 01:40:01 by elorenze          #+#    #+#             */
/*   Updated: 2022/04/07 01:43:16 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_startswith(const char *str, const char *start)
{
	size_t	s;

	s = ft_strlen(start);
	return (ft_memcmp(str, start, s));
}
