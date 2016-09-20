/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 16:45:23 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/17 01:27:29 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	n;
	size_t	len1;
	size_t	len;

	n = 0;
	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2);
	str = (char*)malloc(len * sizeof(*str) + 1);
	if (str)
	{
		str = ft_strcpy(str, s1);
		while (s2[n] != '\0')
		{
			str[len1 + n] = s2[n];
			n++;
		}
		str[len1 + n] = '\0';
		return (str);
	}
	return (NULL);
}
