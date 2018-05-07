/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:13:10 by afoures           #+#    #+#             */
/*   Updated: 2017/11/10 10:59:39 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalcpy(const void *src, size_t size)
{
	void *dest;

	if (!src || size == 0)
		return (NULL);
	if (!(dest = ft_memalloc(size + 1)))
		return (NULL);
	ft_memcpy(dest, src, size);
	return (dest);
}
