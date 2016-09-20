/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:07:38 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/16 23:50:37 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	n;

	if (!s)
		return (NULL);
	n = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '\0')
	{
		str = (char*)malloc(sizeof(*str));
		str[0] = '\0';
		return (str);
	}
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	str = ft_strndup(s, len);
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}
