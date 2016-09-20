/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:31:28 by yboualla          #+#    #+#             */
/*   Updated: 2016/04/14 20:36:23 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnbword(char *str, char c)
{
	int nbword;
	int i;

	i = -1;
	nbword = 0;
	while (str[++i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
		{
			nbword++;
			while (str[i] == c && str[i] != '\0')
				i++;
		}
	}
	return (nbword);
}
