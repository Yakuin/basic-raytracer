/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 20:16:06 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 23:52:41 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char*)s;
	while (tmp[i] != '\0')
	{
		ft_putchar(tmp[i]);
		i++;
	}
}
