/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:44:38 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 00:50:43 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	c;

	if (lst == NULL)
		return (0);
	c = 1;
	while (lst->next)
	{
		lst = lst->next;
		c++;
	}
	return (c);
}
