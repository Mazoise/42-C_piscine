/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:12:45 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/25 18:55:02 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*str;
	char	*ptr;
	int		lg_src;

	str = NULL;
	lg_src = 0;
	while (src[lg_src])
		lg_src++;
	if (!(str = malloc(sizeof(*str) * (lg_src + 1))))
		return (0);
	ptr = str;
	while (*src)
		*ptr++ = *src++;
	*ptr = 0;
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*str;

	str = NULL;
	i = 0;
	if (ac <= 0)
		return (str);
	if (!(str = malloc(sizeof(t_stock_str) * (ac + 1))))
		return ((str = NULL));
	while (i < ac)
	{
		str[i].size = ft_strlen(av[i]);
		str[i].str = av[i];
		str[i].copy = ft_strdup(av[i]);
		i++;
	}
	str[i].str = 0;
	return (str);
}
