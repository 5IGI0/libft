/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 07:47:05 by elorenze          #+#    #+#             */
/*   Updated: 2022/04/19 07:54:19 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

#include <stddef.h>

void	*ft_strndup(const char *str, size_t n)
{
	char	*tmp;

	if (n == 0)
		return (ft_calloc(1, 1));
	if (ft_strlen(str) < n)
		return (ft_strdup(str));
	tmp = ft_memdup(str, n + 1);
	if (!tmp)
		return (NULL);
	tmp[n] = 0;
	return (tmp);
}
