/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 11:35:13 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/25 13:45:10 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstread(t_list *lst)
{
	t_list *cursor;

	cursor = lst;
	if (cursor != NULL)
	{
		while (cursor->next != NULL)
		{
			printf("%s", cursor->content);
			cursor = cursor->next;
		}
		printf("%s", cursor->content);
	}
}
