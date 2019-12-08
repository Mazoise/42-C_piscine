/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: econtrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:48:02 by econtrer          #+#    #+#             */
/*   Updated: 2019/07/21 17:55:25 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char    *ft_strcpy(char *dest, char *src)
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

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int filltab(int *keys, char **print, char *buf)
{
	int i;
	int j;
	int aux;

	i = 0;
	j = 0;
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
		printf("\n%d, %s\n", keys[j - 1], print[j - 1]); //w
	}
	return (0);
}

int main()
{
	int fd;
	int ret;
	int keys[50];
	char *print[50];
	char *buf;

	buf = malloc(sizeof(*buf) * 360);
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error", 5);
		return (1);
	}
	while ((ret = read(fd, buf, 360)))
		buf[ret] = '\0';
	close(fd);
//	printf();
	filltab(keys, print, buf);
	return (0);
}
