/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:40:07 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/12 14:37:28 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_unsign(char *s);

int		ft_unsign(char *s)
{
	unsigned char p;

	p = (unsigned char)*s;
	return (p);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (ft_unsign(&s1[i]) - ft_unsign(&s2[i]));
		else if (i == n)
			return (0);
		else if (s1[i] == 0 && s2[i] == 0)
			return (0);
		i++;
	}
	return (0);
}
