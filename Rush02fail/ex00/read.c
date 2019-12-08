/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: econtrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:48:02 by econtrer          #+#    #+#             */
/*   Updated: 2019/07/21 23:19:43 by econtrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int n;

	n = 0;
	while (src[n] != '\n')
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (dest);
}

int		ft_strlen(char *buf, int i)
{
	int j;

	j = i;
	while (buf[j] != '\n')
		j++;
	return (j - i + 1);
}

int		filltab(unsigned long *keys, char **print, char *buf)
{
	int				i;
	int				j;
	unsigned long	aux;

	i = 0;
	j = 1;
	while (buf[i])
	{
		aux = 0;
		while (buf[i] >= '0' && buf[i] <= '9')
		{
			aux = aux * 10 + buf[i] - 48;
			i++;
		}
		keys[j] = aux;
		while (buf[i] == ':' || buf[i] == ' ')
			i++;
		print[j] = malloc(sizeof(*print[j]) * ft_strlen(buf, i));
		print[j] = ft_strcpy(print[j], &buf[i]);
		i += ft_strlen(buf, i);
		j++;
	}
	return (0);
}

int		ft_creat_tab(unsigned long *keys, char **print, int size)
{
	int		fd;
	int		ret;
	char	*buf;

	if (!(buf = malloc(sizeof(*buf) * (size + 2))))
		return (0);
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, 360)))
		buf[ret] = '\0';
	if (close(fd) == -1)
		return (0);
	filltab(keys, print, buf);
	keys[0] = size;
	free(buf);
	return (1);
}
