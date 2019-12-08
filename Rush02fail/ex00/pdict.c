/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdict.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: econtrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:54:43 by econtrer          #+#    #+#             */
/*   Updated: 2019/07/21 23:17:59 by econtrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_prints(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			write(1, " ", 1);
		while (str[i] == ' ')
			i++;
		write(1, &str[i], 1);
		i++;
	}
}

int		pdict(unsigned long *keys, char **print, unsigned long s)
{
	int i;
	int size;

	i = 1;
	size = keys[0];
	while (size > 0)
	{
		if (s == keys[i])
		{
			ft_prints(print[i]);
			return (1);
		}
		i++;
		size--;
	}
	ft_prints("Dict ");
	return (0);
}
