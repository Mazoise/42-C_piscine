/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:30:32 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/21 15:33:23 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_check_buf(char *buf);
int		ft_count_buf(int argc, char *name);

int		ft_atoi(char *str)
{
	unsigned int		i;
	unsigned long		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

int		ft_check_dict(int argc, char *name)
{
	int		fd;
	char	*buf;
	int		ret;
	int		i;

	if (argc == 3)
		fd = open(name, O_RDONLY);
	else
		fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return (0);
	i = ft_count_buf(argc, name);
	if (!(buf = malloc(sizeof(*buf) * (i + 2))))
		return (0);
	while ((ret = read(fd, buf, i + 1)))
		buf[ret] = '\0';
	if (!(ft_check_buf(buf)))
		return (0);
	if (close(fd) == -1)
		return (0);
	return (i);
}

int		ft_count_buf(int argc, char *name)
{
	int		fd;
	char	bufcount[1];
	int		i;

	i = 0;
	if (argc == 3)
		fd = open(name, O_RDONLY);
	else
		fd = open("numbers.dict", O_RDONLY);
	while (read(fd, bufcount, 1))
		i++;
	if (close(fd) == -1)
		return (0);
	return (i);
}

int		ft_check_buf(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] < '0' || buf[i] > '9')
			return (0);
		while (buf[i] >= '0' && buf[i] <= '9')
			i++;
		while (buf[i] == ' ')
			i++;
		if (buf[i] != ':' )
			return (0);
		i++;
		while (buf[i] == ' ')
			i++;
		if (buf[i] < ' ' || buf[i] > '~')
			return (0);
		while (buf[i] >= ' ' && buf[i] <= '~' && buf[i] != '\n')
			i++;
		if (buf[i] != '\n' && buf[i + 1] != '\0')
			return (0);
		while (buf[i] == '\n')
			i++;
	}
	return (i);
}
