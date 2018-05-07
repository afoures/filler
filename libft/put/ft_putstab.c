/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:19:45 by afoures           #+#    #+#             */
/*   Updated: 2017/11/10 15:04:36 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstab(char **tab)
{
	size_t len;

	len = ft_tablen(tab);
	while (len-- > 0)
	{
		ft_putstr(*tab);
		if (len > 0)
			ft_putstr(" | ");
		tab++;
	}
}