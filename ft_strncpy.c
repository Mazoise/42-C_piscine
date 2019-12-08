/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 20:13:48 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/09 21:11:14 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int increm;

	increm = 0;
	while (increm < n)
	{
		*(dest + increm) = *(src + increm);
		if (src[increm] == 0)
		{
			while (increm < n)
			{
				dest[increm] = 0;
				increm++;
			}
		}
		increm++;
	}
	return (dest);
}
