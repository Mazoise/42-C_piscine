/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:28:45 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/20 19:39:38 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> //warning

int		ft_atoi(char *str);
int		ft_check_name(char *str);
int		ft_check_dict(int argc, char *name);

int		main(int argc, char **argv)
{
	unsigned long nb;

	nb = ft_atoi(argv[argc - 1]);
	if (nb == -1 || nb > 999999999999 
		|| argc > 3 || !(ft_check_dict(argc, argv[1])))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	printf("%lu", nb); //warning
	return (0);
}
