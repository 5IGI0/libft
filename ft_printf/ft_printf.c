/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:29:12 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/24 14:33:11 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include <unistd.h>

#include "ft_printers.h"

int	ft_printf_format(int fd, const char *format, va_list *ap)
{
	if (format[1] == 's')
		return (print_s(fd, va_arg(*ap, char *)));
	if (format[1] == 'c')
		return (print_c(fd, va_arg(*ap, int)));
	if (format[1] == 'd' || format[1] == 'i')
		return (print_lb(fd, va_arg(*ap, int), "0123456789"));
	if (format[1] == 'u')
		return (print_lb(fd, va_arg(*ap, unsigned int), "0123456789"));
	if (format[1] == 'x')
		return (print_lb(fd, va_arg(*ap, unsigned int), "0123456789abcdef"));
	if (format[1] == 'X')
		return (print_lb(fd, va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	if (format[1] == 'p')
		return (print_p(fd, va_arg(*ap, void *)));
	if (format[1] == '%')
		return (print_c(fd, '%'));
	else
		return (write(1, format, 2));
}

int	ft_vdprintf(int fd, const char *format, va_list *ap)
{
	int	written;
	int	ret;

	written = 0;
	if (format[0] == 0)
		return (0);
	while (format[0])
	{
		if (format[0] == '%' && format[1])
		{
			ret = ft_printf_format(fd, format, ap);
			format++;
		}
		else
			ret = write(fd, format, 1);
		if (ret < 0)
			return (-1);
		written += ret;
		format++;
	}
	return (written);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(1, format, &ap);
	va_end(ap);
	return (ret);
}
