/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:43:29 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/09 21:08:07 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	int n;

	n = 0;
	while (src[n] != 0)
	{
		*(dest + n) = *(src + n);
		n++;
	}
	dest[n] = '\0';
	return (dest);
}
