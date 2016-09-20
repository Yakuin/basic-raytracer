/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:29:12 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 03:55:13 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	i = 0;
	tmp_s1 = (unsigned char*)s1;
	tmp_s2 = (unsigned char*)s2;
	while (tmp_s1[i] != '\0' && i < n)
	{
		if (tmp_s1[i] > tmp_s2[i])
			return (1);
		if (tmp_s2[i] > tmp_s1[i])
			return (-1);
		i++;
	}
	if (i == n)
		return (0);
	if (tmp_s1[i] > tmp_s2[i])
		return (1);
	else if (tmp_s2[i] > tmp_s1[i])
		return (-1);
	else
		return (0);
}
