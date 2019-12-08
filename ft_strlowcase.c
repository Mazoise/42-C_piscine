/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:27:31 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/09 15:28:03 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	int n;

	n = 0;
	while (str[n])
	{
		if (str[n] >= 'A' && str[n] <= 'Z')
			str[n] = str[n] + 32;
		n++;
	}
	return (str);
}
