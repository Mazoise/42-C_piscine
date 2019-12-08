/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:21:03 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/09 14:21:55 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int n;

	n = 0;
	while (str[n])
	{
		if (str[n] < 'a' || str[n] > 'z')
			return (0);
		n++;
	}
	return (1);
}
