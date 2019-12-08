/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 09:40:20 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/07 09:42:15 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	ft_putchar(int c);
void	ft_print(int a, int b, int c);

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_print(int a, int b, int c)
{
	ft_putchar(a + '0');
	ft_putchar(b + '0');
	ft_putchar(c + '0');
	if (a < 7)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	c = 0;
	while (a < 10)
	{
		if (a < b && b < c)
			ft_print(a, b, c);
		c++;
		if (c > 9)
		{
			b++;
			c = 0;
		}
		if (b > 9)
		{
			a++;
			b = 0;
			c = 0;
		}
	}
}
