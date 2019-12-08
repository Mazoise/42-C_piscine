/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:38:04 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/09 21:04:46 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr_non_printable(char *str);
void	ft_convert_hexa(char *str, unsigned char *a, unsigned char *b);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_convert_hexa(char *str, unsigned char *a, unsigned char *b)
{
	char			hexa[16];
	unsigned char	pos;

	pos = (char unsigned)*str;
	hexa[0] = '0';
	hexa[1] = '1';
	hexa[2] = '2';
	hexa[3] = '3';
	hexa[4] = '4';
	hexa[5] = '5';
	hexa[6] = '6';
	hexa[7] = '7';
	hexa[8] = '8';
	hexa[9] = '9';
	hexa[10] = 'a';
	hexa[11] = 'b';
	hexa[12] = 'c';
	hexa[13] = 'd';
	hexa[14] = 'e';
	hexa[15] = 'f';
	*a = pos / 16;
	*b = hexa[pos % 16];
}

void	ft_putstr_non_printable(char *str)
{
	int				n;
	unsigned char	a;
	unsigned char	b;

	n = 0;
	while (str[n])
	{
		if (str[n] < ' ' || str[n] > '~')
		{
			ft_convert_hexa(&str[n], &a, &b);
			ft_putchar('\\');
			if (a > 9)
				ft_putchar(a + 87);
			else
				ft_putchar(a + '0');
			ft_putchar(b);
		}
		else
			ft_putchar(str[n]);
		n++;
	}
}
