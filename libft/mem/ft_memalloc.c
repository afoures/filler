/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:22:10 by afoures           #+#    #+#             */
/*   Updated: 2017/11/09 12:37:59 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *dest;

	if (!(dest = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(dest, size);
	return (dest);
}
