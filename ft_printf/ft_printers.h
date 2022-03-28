/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:29:16 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/24 14:33:42 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTERS_H
# define FT_PRINTERS_H

int	print_c(int fd, char c);
int	print_s(int fd, char *str);
int	print_lb(int fd, long n, char *base);
int	print_p(int fd, void *p);

#endif