/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:04:50 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 03:52:31 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*last;

	if (!ft_isascii(c))
		return (NULL);
	last = (NULL);
	ch = c;
	while (*s)
	{
		if (*s == ch)
		{
			last = (char*)s;
			s++;
		}
		else
			s++;
	}
	if (*s == ch)
		return (last = (char*)s);
	else
		return (last);
}
