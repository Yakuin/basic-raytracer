/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:21:49 by yboualla          #+#    #+#             */
/*   Updated: 2016/05/09 17:45:12 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	openfile(char *path)
{
	int		file;

	file = open(path, O_RDONLY);
	if (file == -1)
		return (-1);
	return (file);
}

char		*ft_readfile(char *path)
{
	char	buffer[BUFF_SIZE + 1];
	int		ret;
	char	*str;
	int		fd;

	fd = openfile(path);
	if (!(str = (char*)ft_memalloc(sizeof(char))))
		return (NULL);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (ret == -1)
			return (NULL);
		buffer[ret] = '\0';
		str = ft_strjoin(str, buffer);
	}
	if (ret == -1)
		return (NULL);
	close(fd);
	return (str);
}
