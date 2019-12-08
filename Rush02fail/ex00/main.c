/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:28:45 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/21 23:17:37 by econtrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

long	ft_atoi(char *str);
int		ft_check_dict(int argc, char *name, int *lines);
long	dictcall (long nb, long *keys, char **print);
int		ft_creat_tab(long *keys, char **print, int size);

int		proces(long nb, int lines, int size)
{
	int		r;
	long	*keys;
	char	**print;

	keys = malloc(sizeof(*keys) * lines);
	print = malloc(sizeof(*print) * lines);
	r = ft_creat_tab(keys, print, size);
	r = dictcall(nb, keys, print);
	write(1, "\n", 1);
	free(keys);
	free(print);
	return (r);
}

int		main(int argc, char **argv)
{
	long	nb;
	int		lines;
	int		size;
	int		r;

	lines = 0;
	size = ft_check_dict(argc, argv[1], &lines);
	nb = ft_atoi(argv[argc - 1]);
	if (nb < 0 || nb > 999999999999 || argc > 3 || size == 0)
	{
		r = 0;
	}
	else
	{
		r = proces(nb, lines, size);
	}
	if (r == 0)
		write(1, "Error\n", 6);
	return (0);
}
