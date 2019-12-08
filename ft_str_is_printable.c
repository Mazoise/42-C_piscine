/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:34:34 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/09 14:34:38 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int n;

	n = 0;
	while (str[n])
	{
		if (str[n] < ' ' || str[n] > '~')
			return (0);
		n++;
	}
	return (1);
}
