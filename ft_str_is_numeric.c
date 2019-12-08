/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:15:23 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/09 14:16:40 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int n;

	n = 0;
	while (str[n])
	{
		if (str[n] < '0' || str[n] > '9')
			return (0);
		n++;
	}
	return (1);
}
