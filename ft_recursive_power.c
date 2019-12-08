/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:28:11 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/15 22:02:17 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power);

int		ft_recursive_power(int nb, int power)
{
	int res;

	if (power < 0)
		return (0);
	res = 1;
	if (power > 0)
		res = nb * ft_recursive_power(nb, power - 1);
	return (res);
}
