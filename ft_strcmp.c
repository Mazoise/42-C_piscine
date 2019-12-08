/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:38:10 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/25 12:47:33 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unsign(char *s)
{
	unsigned char p;

	p = (unsigned char)*s;
	return (p);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int n;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == 0 && s2[i] == 0)
			return (0);
		else
			i++;
	}
	n = ft_unsign(&s1[i]) - ft_unsign(&s2[i]);
	return (n);
}
