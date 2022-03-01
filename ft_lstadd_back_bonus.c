/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:19:17 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 00:31:52 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst == NULL)
		return ;
	if (lst[0] == NULL)
		lst[0] = new;
	else
	{
		ptr = lst[0];
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}
