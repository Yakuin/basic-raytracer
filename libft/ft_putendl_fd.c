/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 20:54:34 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 23:55:21 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char*)s;
	while (tmp[i])
	{
		ft_putchar_fd(tmp[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
