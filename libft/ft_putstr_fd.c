/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 20:11:58 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/26 16:52:59 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char*)s;
	while (tmp[i] != '\0')
	{
		ft_putchar_fd(tmp[i], fd);
		i++;
	}
}
