/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <elorenze@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:58:54 by elorenze          #+#    #+#             */
/*   Updated: 2022/03/01 14:03:31 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static t_list	*secure_lstnew(void *content, void (*del)(void *))
{
	t_list	*ret;

	ret = ft_lstnew(content);
	if (ret == NULL)
		del(content);
	return (ret);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*ptr;

	if (lst == NULL)
		return (NULL);
	ret = secure_lstnew(f(lst->content), del);
	if (ret == NULL)
		return (NULL);
	lst = lst->next;
	ptr = ret;
	while (lst)
	{
		ptr->next = secure_lstnew(f(lst->content), del);
		if (ptr->next == NULL)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ptr = ptr->next;
		lst = lst->next;
	}
	return (ret);
}
