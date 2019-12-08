/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:48:31 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/16 18:43:40 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str);
int		ft_isspace(char str);
int		ft_sign(char str);

int		ft_isspace(char str)
{
	return (str == '\t' || str == '\n' || str == '\v'
		|| str == '\r' || str == ' ' || str == '\f');
}

int		ft_sign(char str)
{
	return (str == '+' || str == '-');
}

int		ft_num(char str)
{
	return (str >= '0' && str <= '9');
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (ft_isspace(str[i]))
		i++;
	while (ft_sign(str[i]))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_num(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb = sign * nb;
	return (nb);
}
