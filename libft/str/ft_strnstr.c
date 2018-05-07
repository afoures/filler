/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:28:26 by afoures           #+#    #+#             */
/*   Updated: 2017/11/09 18:12:05 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t size;

	i = 0;
	j = 0;
	size = 0;
	while (needle[size])
		size++;
	if (size == 0)
		return ((char *)haystack);
	while (haystack[i] && len > 0)
	{
		while (haystack[i + j] == needle[j] && len > j)
		{
			if (j == size - 1)
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
		len--;
	}
	return (NULL);
}
