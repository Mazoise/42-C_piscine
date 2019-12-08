/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:46:51 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/23 12:23:37 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(char *str, char *base);
int		ft_check_str(char str, char *base);
int		ft_check_base(char *base);
int		ft_isspace(char str);

int		ft_check_str(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_isspace(char str)
{
	return (str == '\t' || str == '\n' || str == '\v'
			|| str == '\r' || str == ' ' || str == '\f');
}

int		check_b(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
	{
		j = 1;
		if (ft_isspace(base[i]) || base[i] == '+' || base[i] == '-')
			return (-1);
		while (base[j + i])
		{
			if (base[i] == base[j + i])
				return (-1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int				i;
	int				sign;
	int				nb;
	int				b_length;
	int				c;

	i = 0;
	sign = 1;
	nb = 0;
	b_length = check_b(base);
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && (c = ft_check_str(str[i], base)) != -1)
	{
		nb = (nb * b_length) + c;
		i++;
	}
	return (nb * sign);
}
