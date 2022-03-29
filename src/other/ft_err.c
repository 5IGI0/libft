/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:00:57 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/29 08:15:54 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

#include "../../libft.h"
#include "../../ft_printf/ft_printf.h"

void	ft_err(int eval, const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ft_vdprintf(2, fmt, &ap);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	va_end(ap);
	exit(eval);
}

void	ft_errx(int eval, const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ft_vdprintf(2, fmt, &ap);
	ft_putstr_fd("\n", 2);
	va_end(ap);
	exit(eval);
}
