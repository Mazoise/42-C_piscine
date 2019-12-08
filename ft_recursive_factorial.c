/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:41:03 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/16 16:45:04 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb);

int		ft_recursive_factorial(int nb)
{
	int res;

	if (nb < 0)
		return (0);
	res = 1;
	if (nb > 1)
		res = nb * ft_recursive_factorial(nb - 1);
	return (res);
}
