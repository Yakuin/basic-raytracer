/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 03:10:44 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/25 13:55:20 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	newlist = (t_list*)malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	if (!content)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
		newlist->next = NULL;
		return (newlist);
	}
	newlist->content = malloc(sizeof(content) * content_size);
	if (!ft_memcpy(newlist->content, content, content_size))
		return (NULL);
	newlist->next = NULL;
	return (newlist);
}
