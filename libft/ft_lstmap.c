/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 00:55:08 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/21 11:00:02 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*cursor;

	if (lst == NULL || f == NULL)
		return (NULL);
	cursor = f(lst);
	new = f(lst);
	if (!new)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		cursor->next = f(lst);
		cursor = cursor->next;
	}
	return (new);
}
