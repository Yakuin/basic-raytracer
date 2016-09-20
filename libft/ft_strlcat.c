/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 20:10:58 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 03:50:16 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	result;
	char	eos;

	eos = 0;
	i = 0;
	while (i < size && !eos)
	{
		if (dst[i] == '\0')
			eos = 1;
		i += (eos ? 0 : 1);
	}
	result = i + ft_strlen(src);
	n = size - i - 1;
	if (i != size)
	{
		ft_memcpy(dst + i, src, n);
		dst[i + n] = '\0';
	}
	return (result);
}
