/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:48:25 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 03:48:23 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*tmp_dst;
	const char	*tmp_src;
	size_t		i;

	tmp_dst = dst;
	tmp_src = src;
	i = 0;
	while (i < len)
	{
		if (tmp_src[i] == '\0')
			while (i < len)
			{
				tmp_dst[i] = '\0';
				i++;
			}
		else
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	}
	return (tmp_dst);
}
