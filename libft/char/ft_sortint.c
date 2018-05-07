/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:24:22 by afoures           #+#    #+#             */
/*   Updated: 2017/11/10 11:53:34 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sortint(int *tab, size_t size)
{
	size_t	i;
	size_t	n;
	int		tmp;

	i = 0;
	while (i < size)
	{
		n = i;
		while (n < size)
		{
			if (tmp > tab[n])
			{
				tmp = tab[i];
				tab[i] = tab[n];
				tab[n] = tmp;
			}
			n++;
		}
		i++;
	}
}
