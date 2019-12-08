/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:48:55 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/25 19:55:41 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
int		ft_check_base(char *base);
void	ft_put_nbr(long nbr, int count, char *base);

void	ft_put_nbr(long nbr, int count, char *base)
{
	if (nbr >= count)
		ft_put_nbr(nbr / count, count, base);
	write(1, &base[nbr % count], 1);
}

int		ft_check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (base[i])
	{
		if (base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\r' || base[i] == ' ' || base[i] == '\f'
			|| base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j + i])
		{
			if (base[i] == base[j + i])
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		count;
	long	nbrlong;

	count = 0;
	nbrlong = (long)nbr;
	while (base[count])
		count++;
	if (count < 2)
		return ;
	if (!(ft_check_base(base)))
		return ;
	if (nbrlong < 0)
	{
		nbrlong = -nbrlong;
		write(1, "-", 1);
	}
	ft_put_nbr(nbrlong, count, base);
}
