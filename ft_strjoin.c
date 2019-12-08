/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:03:35 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/24 15:13:04 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);
void	ft_strcpy(char *dest, char *src);
int		ft_total_length(int size, char **strs, char *sep);

int		ft_total_length(int size, char **strs, char *sep)
{
	int i;
	int total_length;

	i = 0;
	total_length = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]) + ft_strlen(sep);
		i++;
	}
	return (total_length);
}

void	ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char		*tab;
	int			i;
	int			total_length;

	i = 0;
	if (size <= 0)
	{
		tab = malloc(sizeof(*tab));
		tab[0] = '\0';
		return (tab);
	}
	total_length = ft_total_length(size, strs, sep);
	if (!(tab = malloc(sizeof(*tab) * total_length + 1)))
		return (0);
	total_length = 0;
	while (i < size)
	{
		ft_strcpy(&tab[total_length], strs[i]);
		if (i < size - 1)
			ft_strcpy(&tab[total_length + ft_strlen(strs[i])], sep);
		total_length += ft_strlen(sep) + ft_strlen(strs[i]);
		i++;
	}
	tab[total_length - ft_strlen(sep)] = 0;
	return (tab);
}
