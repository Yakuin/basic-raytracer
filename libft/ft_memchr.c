/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 18:10:09 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 03:44:34 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_tmp;

	i = 0;
	s_tmp = (unsigned char*)s;
	while (i < n)
	{
		if (s_tmp[i] == (unsigned char)c)
			return (&s_tmp[i]);
		i++;
	}
	return (NULL);
}
