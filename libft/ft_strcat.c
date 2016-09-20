/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 19:11:55 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 03:49:08 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*tmp_s1;
	char	*tmp_s2;
	size_t	i;
	size_t	i2;

	tmp_s1 = s1;
	tmp_s2 = (char *)s2;
	i = ft_strlen(s1);
	i2 = 0;
	while (tmp_s2[i2] != '\0')
	{
		tmp_s1[i + i2] = tmp_s2[i2];
		i2++;
	}
	tmp_s1[i + i2] = '\0';
	return (tmp_s1);
}
