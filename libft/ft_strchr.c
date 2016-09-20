/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:28:10 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 03:51:32 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	if (!ft_isascii(c))
		return (NULL);
	else
		ch = c;
	while (*s)
	{
		if (*s == ch)
			return ((char*)s);
		else
			s++;
	}
	if (*s == ch)
		return ((char*)s);
	else
		return (NULL);
}
