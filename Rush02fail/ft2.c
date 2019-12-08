/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictcall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: econtrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:13:42 by econtrer          #+#    #+#             */
/*   Updated: 2019/07/20 18:51:40 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned long	dictcall(unsigned long nb);

unsigned long	zeroz(unsigned long nb, unsigned long max)
{
	unsigned long d;
	unsigned long r;

	d = max / 10;
	r = 0;
	if (d == 10)
		printf(" %lu ", (nb / 10) * 10);
	else
	{
		printf(" %lu ", (nb / d));
		printf(" %lu ", d);
	}
	d = nb % d;
	if (d != 0)
		r = dictcall(d);
	return (r);
}

unsigned long	lotzero(unsigned long nb, unsigned long max)
{
	unsigned long r;
	unsigned long d;

	r = dictcall(nb / max);
	printf(" %lu ", max);
	d = nb % max;
	if (d != 0)
		r = dictcall(nb % max);
	return (r);
}

unsigned long	dictcall(unsigned long nb)
{
	unsigned long u;
	unsigned long d;
	unsigned long r;

	r = 0;
	if (nb < 20)
	{
		printf(" %lu ", nb);
		return (1);
	}
	else if (nb < 100)
		r = zeroz(nb, 100);
	else if (nb < 1000)
		r = zeroz(nb, 1000);
	else if (nb < 1000000)
		r = lotzero(nb, 1000);
	else if (nb < 1000000000)
		r = lotzero(nb, 1000000);
	else
		r = lotzero(nb, 1000000000);
	return (r);
}

int	main()
{
	printf("\n\n%lu\n", dictcall(999999999999));
}
