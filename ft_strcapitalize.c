/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:39:54 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/09 16:08:43 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

char	*ft_strcapitalize(char *str)
{
	int n;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	n = 1;
	while (str[n])
	{
		if (str[n - 1] < '0' || (str[n - 1] > '9' && str[n - 1] < 'A')
			|| (str[n - 1] > 'Z' && str[n - 1] < 'a') || str[n - 1] > 'z')
		{
			if (str[n] >= 'a' && str[n] <= 'z')
				str[n] = str[n] - 32;
		}
		else
		{
			if (str[n] >= 'A' && str[n] <= 'Z')
				str[n] = str[n] + 32;
		}
		n++;
	}
	return (str);
}
