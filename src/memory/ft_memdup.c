/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 07:38:57 by elorenze          #+#    #+#             */
/*   Updated: 2022/04/19 07:54:10 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libft.h"

void	*ft_memdup(const void *str, size_t n)
{
	char	*tmp;

	tmp = malloc(n);
	if (!tmp)
		return (0);
	return (ft_memcpy(tmp, str, n));
}
