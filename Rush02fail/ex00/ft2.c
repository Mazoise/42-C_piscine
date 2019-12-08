/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictcall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: econtrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:13:42 by econtrer          #+#    #+#             */
/*   Updated: 2019/07/21 23:30:11 by econtrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		pdict(long *keys, char **print, int nb);
long	dictcall(long nb, long *keys, char **print);

long	zeroz(long nb, long max, long *keys, char **print)
{
	long d;
	long r;

	d = max / 10;
	r = 0;
	if (d == 10)
	{
		pdict(keys, print, (nb / 10) * 10);
		write(1, " ", 1);
	}
	else
	{
		pdict(keys, print, (nb / d));
		write(1, " ", 1);
		pdict(keys, print, d);
		write(1, " ", 1);
	}
	d = nb % d;
	if (d != 0)
		r = dictcall(d, keys, print);
	return (r);
}

long	lotzero(long nb, long max, long *keys, char **print)
{
	long r;
	long d;

	r = dictcall(nb / max, keys, print);
	write(1, " ", 1);
	pdict(keys, print, max);
	write(1, " ", 1);
	d = nb % max;
	if (d != 0)
		r = dictcall(nb % max, keys, print);
	return (r);
}

long	dictcall(long nb, long *keys, char **print)
{
	long r;

	r = 0;
	if (nb < 20)
	{
		pdict(keys, print, nb);
		return (1);
	}
	else if (nb < 100)
		r = zeroz(nb, 100, keys, print);
	else if (nb < 1000)
		r = zeroz(nb, 1000, keys, print);
	else if (nb < 1000000)
		r = lotzero(nb, 1000, keys, print);
	else if (nb < 1000000000)
		r = lotzero(nb, 1000000, keys, print);
	else
		r = lotzero(nb, 1000000000, keys, print);
	return (r);
}
