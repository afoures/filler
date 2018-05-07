/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:20:41 by afoures           #+#    #+#             */
/*   Updated: 2017/11/09 18:12:08 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen((char *)s);
	if (c == '\0')
		return ((char *)s + len);
	while (len-- > 0)
	{
		if (s[len] == (unsigned char)c)
			return ((char *)s + len);
	}
	return (NULL);
}
