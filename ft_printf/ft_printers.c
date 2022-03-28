/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:29:19 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/28 07:56:14 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "../libft.h"

int	print_c(int fd, char c)
{
	return (write(fd, &c, 1));
}

int	print_s(int fd, char *str)
{
	if (str == NULL)
		return (write(fd, "(null)", 6));
	return (write(fd, str, ft_strlen(str)));
}

int	print_ulb(int fd, unsigned long n, char *base)
{
	int		written;
	int		ret;
	size_t	bsize;

	written = 0;
	bsize = ft_strlen(base);
	if ((n / bsize))
	{
		ret = print_ulb(fd, n / bsize, base);
		if (ret < 0)
			return (-1);
		written += ret;
	}
	ret = print_c(fd, base[n % bsize]);
	if (ret < 0)
		return (-1);
	return (written + ret);
}

int	print_lb(int fd, long n, char *base)
{
	int	written;
	int	ret;

	written = 0;
	if (n < 0)
	{
		written = print_c(fd, '-');
		if (written < 0)
			return (-1);
		n = -n;
	}
	ret = print_ulb(fd, n, base);
	if (ret < 0)
		return (-1);
	return (ret + written);
}

int	print_p(int fd, void *p)
{
	int	ret;

	ret = write(fd, "0x", 2);
	if (ret < 0)
		return (-1);
	ret = print_ulb(fd, (unsigned long)p, "0123456789abcdef");
	if (ret < 0)
		return (-1);
	return (ret + 2);
}
