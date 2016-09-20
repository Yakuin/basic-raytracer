/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:36:03 by yboualla          #+#    #+#             */
/*   Updated: 2016/04/12 18:54:03 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoinf(char *s1, char *s2)
{
	char		*str;
	size_t		n;
	size_t		len1;
	size_t		len;

	n = 0;
	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2);
	str = (char*)malloc(len * sizeof(*str) + 1);
	if (str)
	{
		str = ft_strcpy(str, s1);
		while (s2[n] != '\0')
		{
			str[len1 + n] = s2[n];
			n++;
		}
		str[len1 + n] = '\0';
		ft_strdel(&s1);
		return (str);
	}
	return (NULL);
}

int				check_str(char *cont, char **cont2, char **line)
{
	int			i;

	i = -1;
	while (cont[++i] != '\0')
	{
		if (cont[i] == '\n' || cont[i] == -1)
		{
			*line = ft_strsub(cont, 0, i);
			*cont2 = ft_strsub(cont, i + 1, ft_strlen(cont) - i - 1);
			return (1);
		}
	}
	return (0);
}

int				check_cont(char **cont2, char **cont, char **line)
{
	if (cont2 != NULL)
	{
		*cont = ft_strdup((char *const)*cont2);
		if (check_str(*cont, cont2, line))
			return (1);
		*cont2 = "\0";
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		*cont;
	static char	*cont2 = "\0";
	char		buffer[BUFF_SIZE + 1];

	cont = NULL;
	if (fd < 0 || !line)
		return (-1);
	if (check_cont(&cont2, &cont, line))
		return (1);
	ret = read(fd, buffer, BUFF_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		cont = ft_strjoinf(cont, buffer);
		if (check_str(cont, &cont2, line))
			return (1);
		ret = read(fd, buffer, BUFF_SIZE);
	}
	if (ret == -1)
		return (-1);
	*line = cont;
	if (*line[0] == '\0')
		return (0);
	return (1);
}
