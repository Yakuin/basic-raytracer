/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:09:22 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/17 01:52:29 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		result;
	size_t	i;
	int		isnegative;

	isnegative = 0;
	i = 0;
	result = 0;
	while (ft_iscntrl(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isnegative = 1;
		i++;
	}
	if (ft_iscntrl(str[i]))
		return (0);
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (isnegative ? -result : result);
}
