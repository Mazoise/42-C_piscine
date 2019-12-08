/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:25:35 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/09 14:26:04 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int n;

	n = 0;
	while (str[n])
	{
		if (str[n] < 'A' || str[n] > 'Z')
			return (0);
		n++;
	}
	return (1);
}
