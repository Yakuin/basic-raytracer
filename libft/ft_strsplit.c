/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 20:31:09 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/24 17:27:52 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	int	wordnb;
	int	i;

	i = 0;
	wordnb = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (wordnb);
		wordnb++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (wordnb);
}

static char		**ft_mallolettercount(char const *s, char c, char **strarray)
{
	size_t	i;
	size_t	i2;
	size_t	len;

	len = 0;
	i = 0;
	i2 = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (strarray);
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			len++;
		}
		strarray[i2] = (char*)malloc(sizeof(*strarray) * len + 1);
		if (!strarray[i2])
			return (NULL);
		len = 0;
		i2++;
	}
	return (strarray);
}

static char		**ft_arrayfill(char const *s, char c, char **strarray)
{
	size_t	i;
	size_t	i2;
	size_t	len;

	i = 0;
	i2 = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
		{
			strarray[i2] = NULL;
			return (strarray);
		}
		while (s[i] != c && s[i] != '\0')
			strarray[i2][len++] = s[i++];
		strarray[i2][len] = '\0';
		len = 0;
		i2++;
	}
	strarray[i2] = NULL;
	return (strarray);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**strarray;
	size_t	wordnb;

	wordnb = ft_wordcount(s, c);
	strarray = (char**)malloc(sizeof(*strarray) * wordnb + 1);
	if (!strarray)
		return (NULL);
	strarray = ft_mallolettercount(s, c, strarray);
	if (!strarray)
		return (NULL);
	strarray = ft_arrayfill(s, c, strarray);
	return (strarray);
}
