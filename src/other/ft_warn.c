/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_warn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:00:57 by elorenze          #+#    #+#             */
/*   Updated: 2022/04/15 09:04:00 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdarg.h>

#include "../../libft.h"
#include "../../ft_printf/ft_printf.h"

void	ft_warn(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ft_vdprintf(2, fmt, &ap);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	va_end(ap);
}

void	ft_warnx(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ft_vdprintf(2, fmt, &ap);
	ft_putstr_fd("\n", 2);
	va_end(ap);
}

int	ft_warnretx(int ret, const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ft_vdprintf(2, fmt, &ap);
	ft_putstr_fd("\n", 2);
	va_end(ap);
	return (ret);
}

int	ft_warnret(int ret, const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ft_vdprintf(2, fmt, &ap);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	va_end(ap);
	return (ret);
}
