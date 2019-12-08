/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:11:55 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/23 19:01:36 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max);

int		*ft_range(int min, int max)
{
	int *tab;
	int size;
	int i;

	i = 0;
	size = max - min;
	if (size <= 0)
		return (0);
	if (!(tab = malloc(sizeof(*tab) * size)))
		return (0);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
