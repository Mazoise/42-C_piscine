/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:56:23 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/06 20:44:12 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	ft_putchar(int c);
void	ft_print(int a, int b, int c, int d);

void	ft_print(int a, int b, int c, int d)
{
	ft_putchar(a + '0');
	ft_putchar(b + '0');
	ft_putchar(' ');
	ft_putchar(c + '0');
	ft_putchar(d + '0');
	if (a != 9 || b != 8 || c != 9 || d != 9)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_increm(int *a, int *b, int *c, int *d)
{
	*d = *d + 1;
	if (*d > 9)
	{
		*c = *c + 1;
		*d = 0;
	}
	if (*c > 9)
	{
		*b = *b + 1;
		*c = 0;
		*d = 0;
	}
	if (*b > 9)
	{
		*a = *a + 1;
		*b = 0;
		*c = 0;
		*d = 0;
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;
	int c;
	int d;

	a = 0;
	b = 0;
	c = 0;
	d = 1;
	while (a < 10)
	{
		if ((a != c || b != d) && (10 * a + b) < (10 * c + d))
			ft_print(a, b, c, d);
		ft_increm(&a, &b, &c, &d);
	}
}
