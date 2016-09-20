/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:30:21 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 03:43:03 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	unsigned char	tmp_c;

	i = 0;
	tmp_dest = (unsigned char*)dst;
	tmp_src = (unsigned char*)src;
	tmp_c = (unsigned char)c;
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		if (tmp_src[i] == tmp_c)
			return (&tmp_dest[i] + 1);
		else
			i++;
	}
	return (NULL);
}
