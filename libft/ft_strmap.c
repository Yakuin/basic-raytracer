/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 19:58:28 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/17 01:27:41 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*tmp_s;
	char	*str;

	i = 0;
	tmp_s = (char*)s;
	str = (char*)malloc(ft_strlen(s) * sizeof(*s) + 1);
	if (str)
	{
		while (tmp_s[i] != '\0')
		{
			str[i] = f(tmp_s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
