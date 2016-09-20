/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:54:07 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 03:54:44 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	i = 0;
	tmp_s1 = (unsigned char*)s1;
	tmp_s2 = (unsigned char*)s2;
	while (tmp_s1[i] != '\0')
	{
		if (tmp_s1[i] > tmp_s2[i])
			return (1);
		if (tmp_s2[i] > tmp_s1[i])
			return (-1);
		i++;
	}
	if (tmp_s1[i] > tmp_s2[i])
		return (1);
	if (tmp_s2[i] > tmp_s1[i])
		return (-1);
	return (0);
}
