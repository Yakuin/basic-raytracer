/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 16:17:44 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 23:49:11 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	tmp1 = (char*)s1;
	tmp2 = (char*)s2;
	i = 0;
	if (tmp1 == tmp2)
		return (1);
	if (tmp1[0] == '\0' || tmp2[0] == '\0')
	{
		if (tmp2[0] == '\0' && tmp2[0] == '\0')
			return (1);
		else
			return (0);
	}
	while (tmp1[i] == tmp2[i])
	{
		if (tmp1[i] == tmp2[i] == '\0' || i == n - 1)
			return (1);
		i++;
	}
	return (0);
}
