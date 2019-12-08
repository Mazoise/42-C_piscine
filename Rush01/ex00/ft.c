/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbugnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:14:54 by cbugnon           #+#    #+#             */
/*   Updated: 2019/07/14 10:05:20 by cbugnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		get_arg_len(char *str)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && str[i] > 47 && str[i] < 58)
			nb++;
		else if (i % 2 == 1 && str[i] != 32)
			return (0);
		i++;
	}
	if (i == 0 || str[i - 1] < 48 || str[i - 1] > 57)
		return (0);
	return (nb);
}

int		*get_arg_int(char *str)
{
	int		*arg_int;
	int		i;
	int		arg_len;

	i = 0;
	arg_len = get_arg_len(str);
	if (!(arg_int = malloc(arg_len * sizeof(int))))
		return (NULL);
	while (i < arg_len * 2)
	{
		arg_int[i / 2] = str[i] - 48;
		i += 2;
	}
	return (arg_int);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	print_final(int *res_tab, int n)
{
	int		i;
	char	c;

	if (res_tab[n * n - 1] == 0)
		print_error();
	else
	{
		i = 0;
		while (i < n * n)
		{
			c = res_tab[i] + 48;
			write(1, &c, 1);
			if (i % n == n - 1)
				write(1, "\n", 1);
			if (i % n < n - 1)
				write(1, " ", 1);
			i++;
		}
	}
}
