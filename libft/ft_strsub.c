/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 16:31:04 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 23:49:39 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;

	n = 0;
	str = (char*)malloc(len * sizeof(*str) + 1);
	if (str)
	{
		while (n < len)
		{
			str[n] = s[n + start];
			n++;
		}
		str[n] = '\0';
		return (str);
	}
	return (NULL);
}
