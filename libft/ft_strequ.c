/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 15:57:43 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 23:48:43 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	tmp1 = (char*)s1;
	tmp2 = (char*)s2;
	i = 0;
	if (tmp1 == tmp2)
		return (1);
	if (tmp1[0] == '\0')
	{
		if (tmp2[0] == '\0')
			return (1);
		else
			return (0);
	}
	while (tmp1[i] == tmp2[i])
	{
		if (tmp1[i] == tmp2[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
