/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbugnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:57:39 by cbugnon           #+#    #+#             */
/*   Updated: 2019/07/14 18:28:40 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_arg_len(char *str);
int		check_up(int *res_tab, int *pos, int *arg_tab, int n);
int		check_down(int *res_tab, int *pos, int *arg_tab, int n);
int		check_left(int *res_tab, int *pos, int *arg_tab, int n);
int		check_right(int *res_tab, int *pos, int *arg_tab, int n);
void	print_final(int *res_tab, int n);

int		*init_res_tab(int n)
{
	int		*res_tab;
	int		i;

	if (!(res_tab = malloc(n * n * sizeof(int) * 10)))
		return (NULL);
	i = 0;
	while (i < n * n)
	{
		res_tab[i] = 0;
		i++;
	}
	return (res_tab);
}

int		check(int *res_tab, int *pos, int *arg_tab, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (pos[0] * n + pos[1] != pos[0] * n + i
			&& res_tab[pos[0] * n + pos[1]] == res_tab[pos[0] * n + i])
			return (0);
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (pos[0] * n + pos[1] != i * n + pos[1]
			&& res_tab[pos[0] * n + pos[1]] == res_tab[i * n + pos[1]])
			return (0);
		i++;
	}
	if ((pos[0] % n == n - 1 && (!check_up(res_tab, pos, arg_tab, n)
		|| !check_down(res_tab, pos, arg_tab, n)))
		|| (pos[1] % n == n - 1 && (!check_left(res_tab, pos, arg_tab, n)
		|| !check_right(res_tab, pos, arg_tab, n))))
		return (0);
	return (1);
}

int		*back_tracking(int *res_tab, int index, int *arg_tab, int n)
{
	int		pos[2];
	int		i;

	i = 1;
	pos[0] = index / n;
	pos[1] = index % n;
	if (res_tab[index] != 0 && index == n * n - 1)
		return (res_tab);
	while (i <= n)
	{
		res_tab[index] = i;
		if (check(res_tab, pos, arg_tab, n) && index < (n * n) - 1)
		{
			res_tab = back_tracking(res_tab, index + 1, arg_tab, n);
			if (res_tab[n * n - 1] != 0)
				return (res_tab);
		}
		else if (check(res_tab, pos, arg_tab, n))
			return (res_tab);
		i++;
	}
	res_tab[index] = 0;
	return (res_tab);
}

int		*get_solution(int *arg_tab, int n)
{
	int		*res_tab;

	if (!(res_tab = init_res_tab(n)))
		return (NULL);
	res_tab = back_tracking(res_tab, 0, arg_tab, n);
	return (res_tab);
}
