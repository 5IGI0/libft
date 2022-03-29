/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:01:20 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/29 07:57:13 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

#include "../../libft.h"

static size_t	get_int_size(int n)
{
	size_t	s;

	if (n == 0)
		return (1);
	s = 0;
	if (n < 0)
	{
		if (n == INT_MIN)
			n += 1;
		n *= -1;
		s++;
	}
	while (n > 0)
	{
		n /= 10;
		s++;
	}
	return (s);
}

/* j'utilise un `long long` parce que j'ai pas envie de me prendre la tête */
/* mais c'est pas forcément portable, donc j'aime pas trop */
char	*ft_itoa(int n)
{
	char		*ret;
	long long	nbr;
	size_t		i;

	nbr = n;
	i = get_int_size(n);
	ret = malloc(i + 1);
	if (ret == NULL)
		return (NULL);
	ret[i] = 0;
	if (nbr < 0)
	{
		ret[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		ret[0] = '0';
	while (nbr > 0)
	{
		i--;
		ret[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (ret);
}
