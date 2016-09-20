/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:28:34 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 03:47:17 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*tmp_s1;

	len = ft_strlen(s1);
	tmp_s1 = (char*)malloc(len * sizeof(*s1) + 1);
	if (tmp_s1 == NULL)
		return (NULL);
	tmp_s1 = ft_strcpy(tmp_s1, s1);
	return (tmp_s1);
}
