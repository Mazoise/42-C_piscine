/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:20:26 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/24 18:17:15 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_put_nbr(int nb)
{
	char a;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -1 * nb;
	}
	if (nb > 9)
		ft_put_nbr(nb / 10);
	a = nb % 10 + '0';
	write(1, &a, 1);
}

void	ft_put_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	if (par == NULL)
		return ;
	while (par[i].str != 0)
	{
		ft_put_str(par[i].str);
		ft_put_nbr(par[i].size);
		write(1, "\n", 1);
		if (par[i].copy)
			ft_put_str(par[i].copy);
		i++;
	}
}
