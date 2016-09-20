/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 19:28:12 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/17 01:28:17 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*tmp_s1;

	tmp_s1 = (char*)malloc(len * sizeof(*s1) + 1);
	if (tmp_s1 == NULL)
		return (NULL);
	tmp_s1 = ft_strncpy(tmp_s1, s1, len);
	return (tmp_s1);
}
