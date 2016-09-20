/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 14:48:33 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/24 16:48:01 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbnum(int n, int neg)
{
	int size;

	size = 0;
	if ((n > 0) || (n < 0))
		size = nbnum(n / 10, neg) + 1;
	return (size);
}

static char		*ft_check(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	else
		return (0);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		size;
	int		neg;

	if (ft_check(n))
		return (str = ft_check(n));
	neg = (n < 0 ? 1 : 0);
	size = nbnum(n, neg);
	size = (neg ? size + 1 : size);
	str = (char*)malloc((size + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	n = (n < 0 ? -n : n);
	i = size - 1;
	while (i >= neg)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (neg)
		str[0] = '-';
	str[size] = '\0';
	return (str);
}
