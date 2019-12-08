/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbugnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:58:11 by cbugnon           #+#    #+#             */
/*   Updated: 2019/07/14 07:32:08 by cbugnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_arg_len(char *str);

int		check_up(int *res_tab, int *pos, int *arg_tab, int n)
{
	int		i;
	int		visible_box;
	int		tallest_box;

	i = 1;
	visible_box = 1;
	tallest_box = res_tab[pos[1]];
	while (i < n)
	{
		if (tallest_box < res_tab[i * n + pos[1]])
		{
			visible_box++;
			tallest_box = res_tab[i * n + pos[1]];
		}
		i++;
	}
	return (visible_box == arg_tab[pos[1]]);
}

int		check_down(int *res_tab, int *pos, int *arg_tab, int n)
{
	int		i;
	int		visible_box;
	int		tallest_box;

	i = n - 2;
	visible_box = 1;
	tallest_box = res_tab[n * (n - 1) + pos[1]];
	while (i >= 0)
	{
		if (tallest_box < res_tab[i * n + pos[1]])
		{
			visible_box++;
			tallest_box = res_tab[i * n + pos[1]];
		}
		i--;
	}
	return (visible_box == arg_tab[n + pos[1]]);
}

int		check_left(int *res_tab, int *pos, int *arg_tab, int n)
{
	int		i;
	int		visible_box;
	int		tallest_box;

	i = 1;
	visible_box = 1;
	tallest_box = res_tab[n * pos[0]];
	while (i <= pos[1])
	{
		if (tallest_box < res_tab[pos[0] * n + i])
		{
			visible_box++;
			tallest_box = res_tab[pos[0] * n + i];
		}
		i++;
	}
	return (visible_box == arg_tab[n * 2 + pos[0]]);
}

int		check_right(int *res_tab, int *pos, int *arg_tab, int n)
{
	int		i;
	int		visible_box;
	int		tallest_box;

	i = n - 2;
	visible_box = 1;
	tallest_box = res_tab[n - 1 + n * pos[0]];
	while (i >= 0)
	{
		if (tallest_box < res_tab[pos[0] * n + i])
		{
			visible_box++;
			tallest_box = res_tab[pos[0] * n + i];
		}
		i--;
	}
	return (visible_box == arg_tab[n * 3 + pos[0]]);
}
