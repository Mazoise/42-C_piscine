/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:45:50 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/23 12:48:38 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		check_b(char *base);

void	ft_nb_zero(char *base_to, char *new_base)
{
	new_base[0] = base_to[0];
	new_base[1] = '\0';
}

int		ft_count_malloc(int nb, int lg_base)
{
	int count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / lg_base;
		count++;
	}
	return (count);
}

int		ft_convnbr_base(long nbr, int lg_nb, char *base_to, char *new_base)
{
	int		lg_base;

	lg_base = check_b(base_to);
	if (nbr >= lg_base)
		ft_convnbr_base(nbr / lg_base, lg_nb - 1, base_to, new_base);
	new_base[lg_nb - 1] = base_to[nbr % lg_base];
	return (*new_base);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb;
	int		lg_base_to;
	int		lg_nb;
	char	*new_base;

	if ((lg_base_to = check_b(base_to)) == -1 || check_b(base_from) == -1)
		return (0);
	if ((nb = ft_atoi_base(nbr, base_from)) == 0)
	{
		new_base = malloc(sizeof(*new_base) * 2);
		ft_nb_zero(base_to, new_base);
		return (new_base);
	}
	lg_nb = ft_count_malloc(nb, lg_base_to);
	if (!(new_base = malloc(sizeof(*new_base) * (lg_nb + 2))))
		return (0);
	if (nb < 0)
	{
		new_base[0] = '-';
		lg_nb++;
		nb = -nb;
	}
	ft_convnbr_base(nb, lg_nb, base_to, new_base);
	new_base[lg_nb] = '\0';
	return (new_base);
}
