/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:39:39 by mchardin          #+#    #+#             */
/*   Updated: 2019/07/08 15:08:04 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);
void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int increm;
	int redo;

	increm = 0;
	redo = 0;
	while (redo < size)
	{
		while (increm < size)
		{
			if (*(tab + increm) > *(tab + increm + 1))
				ft_swap((tab + increm), (tab + increm + 1));
			increm++;
		}
		increm = 0;
		redo++;
	}
}
