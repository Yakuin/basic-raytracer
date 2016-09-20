/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:27:49 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 03:53:21 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	ibig;
	size_t	ilittle;

	ibig = 0;
	ilittle = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[ibig] != '\0')
	{
		if (big[ibig] == little[ilittle])
		{
			ibig++;
			ilittle++;
			if (little[ilittle] == '\0')
				return ((char*)&big[ibig - ilittle]);
		}
		else
		{
			ibig -= ilittle - 1;
			ilittle = 0;
		}
	}
	return (NULL);
}
