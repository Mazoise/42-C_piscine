/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:56:46 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/09 18:00:21 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int increm;
	unsigned int lg_src;

	increm = 0;
	lg_src = 0;
	while (src[lg_src])
		lg_src++;
	if (size == 0)
		return (lg_src);
	while (src[increm] && increm < size - 1)
	{
		*(dest + increm) = *(src + increm);
		increm++;
	}
	dest[increm] = '\0';
	return (lg_src);
}
