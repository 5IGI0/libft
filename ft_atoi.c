/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:09:20 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 14:48:48 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

static const char	*skip_spaces(const char *str)
{
	while (
		str[0] == '\f'
		|| str[0] == '\n'
		|| str[0] == '\r'
		|| str[0] == '\t'
		|| str[0] == '\v'
		|| str[0] == ' '
	)
		str++;
	return (str);
}

static int	ft_atoi_sub(int sign, const char *str, const char *start)
{
	int	ret;
	int	mult;

	ret = 0;
	mult = 1;
	while (str > start)
	{
		str--;
		ret += (str[0] - '0') * mult;
		mult *= 10;
		if (ret == INT_MIN && str == start && sign == -1)
			return (INT_MIN);
	}
	return (ret * sign);
}

int	ft_atoi(const char *str)
{
	int			sign;
	const char	*start;

	if (str == NULL)
		return (0);
	sign = 1;
	str = skip_spaces(str);
	start = str;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		str++;
		start++;
	}
	while (str[0] >= '0' && str[0] <= '9')
		str++;
	return (ft_atoi_sub(sign, str, start));
}
