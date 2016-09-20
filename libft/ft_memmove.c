/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:53:20 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/20 04:48:20 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	unsigned char	*tmp_tmp;

	i = 0;
	tmp_dest = (unsigned char*)dest;
	tmp_src = (unsigned char*)src;
	tmp_tmp = (unsigned char*)malloc(sizeof(unsigned char) * n);
	while (i < n)
	{
		tmp_tmp[i] = tmp_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		tmp_dest[i] = tmp_tmp[i];
		i++;
	}
	free(tmp_tmp);
	return (dest);
}
