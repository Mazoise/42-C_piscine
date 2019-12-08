/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbugnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:06:51 by cbugnon           #+#    #+#             */
/*   Updated: 2019/07/14 13:42:45 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_arg_len(char *str);
int		*get_arg_int(char *str);
int		*get_solution(int *arg_tab, int n);
void	print_final(int *res_tab, int n);
void	print_error(void);

int		main(int ac, char **av)
{
	int	*arg_tab;
	int	*res_tab;
	int	nb_arg;

	nb_arg = 0;
	if ((ac != 2 || get_arg_len(av[1]) % 4 != 0 || get_arg_len(av[1]) < 12)
		|| get_arg_len(av[1]) > 36)
		print_error();
	else
	{
		nb_arg = get_arg_len(av[1]);
		if (!(arg_tab = get_arg_int(av[1])))
			print_error();
		else if (!(res_tab = get_solution(arg_tab, nb_arg / 4)))
			print_error();
		else
		{
			print_final(res_tab, nb_arg / 4);
			free(res_tab);
		}
		free(arg_tab);
	}
	return (0);
}
