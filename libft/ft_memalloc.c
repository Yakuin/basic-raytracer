/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:36:46 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 23:42:56 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memalloc;

	if (!size)
		return (NULL);
	memalloc = malloc(size);
	if (memalloc)
		ft_bzero(memalloc, size);
	return (memalloc);
}
