/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:36:08 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 03:47:54 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int			i;
	char		*tmp_dst;
	const char	*tmp_src;

	tmp_dst = dst;
	tmp_src = src;
	i = 0;
	while (tmp_src[i] != '\0')
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	tmp_dst[i] = tmp_src[i];
	return (tmp_dst);
}
