/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 04:16:20 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/24 13:34:26 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (*alst != NULL && del != NULL)
	{
		while ((*alst)->next != NULL)
		{
			ft_lstdelone(alst, del);
			(*alst)->next = *alst;
		}
		ft_lstdelone(alst, del);
	}
}
