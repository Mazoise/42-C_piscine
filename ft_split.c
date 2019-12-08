/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:39:21 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/23 18:51:06 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strcmp(char s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		if (s1 == s2[i])
			return (1);
		else
			i++;
	}
	return (0);
}

int			ft_strcpy(char **dest, char *src, char *charset)
{
	int i;
	int size;

	size = 0;
	i = 0;
	while (src[size] != 0 && !(ft_strcmp(src[size], charset)))
		size++;
	if (!(dest[0] = malloc(sizeof(*dest) * (size + 1))))
		return (0);
	while (src[i] != 0 && !(ft_strcmp(src[i], charset)))
	{
		dest[0][i] = src[i];
		i++;
	}
	dest[0][i] = '\0';
	return (i);
}

void		ft_splitit(char **splittab, char *str, char *charset)
{
	int count;
	int i;
	int str_size;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (ft_strcmp(str[i], charset))
			i++;
		else
		{
			str_size = ft_strcpy(&splittab[count], &str[i], charset);
			i = i + str_size;
			count++;
		}
	}
	splittab[count] = 0;
}

char		**ft_split(char *str, char *charset)
{
	int		i;
	int		count;
	char	**splittab;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], charset))
			count++;
		i++;
	}
	if (!(splittab = malloc(sizeof(splittab) * (count + 2))))
		return (0);
	ft_splitit(splittab, str, charset);
	return (splittab);
}
