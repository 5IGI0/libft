/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:24:43 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/04 19:01:24 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

size_t	gnl_strlen(char *str);
int		gnl_append(char **dest, char *src);
char	*get_next_line(int fd);

#endif