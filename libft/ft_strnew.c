/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 21:04:44 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 23:45:34 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(size * sizeof(*str) + 1);
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
