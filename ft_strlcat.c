/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:18:12 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/11 12:51:12 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int increm;
	unsigned int decrem;
	unsigned int lg_src;
	unsigned int lg_dest;

	increm = 0;
	lg_src = 0;
	lg_dest = 0;
	while (src[lg_src])
		lg_src++;
	while (dest[lg_dest])
		lg_dest++;
	decrem = lg_src;
	if (size < lg_dest + 1)
		return (size + lg_src);
	while (size - 1 > increm + lg_dest && decrem > 0)
	{
		dest[lg_dest + increm] = src[increm];
		increm++;
		decrem--;
	}
	dest[increm + lg_dest] = '\0';
	return (lg_dest + lg_src);
}
