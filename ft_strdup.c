/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:50:27 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/18 20:44:06 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);

char	*ft_strdup(char *src)
{
	char	*str;
	char	*ptr;
	int		lg_src;

	lg_src = 0;
	while (src[lg_src])
		lg_src++;
	str = malloc(sizeof(*src) * lg_src + 1);
	ptr = str;
	while (*src)
		*ptr++ = *src++;
	*ptr = 0;
	return (str);
}
