/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:27:44 by afoures           #+#    #+#             */
/*   Updated: 2017/11/09 18:39:26 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;
	int		i;
	char	*dest;

	if (!s)
		return (NULL);
	start = 0;
	i = -1;
	end = ft_strlen((char *)s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (end < 0)
		return (ft_strnew(1));
	len = (end + 1) - start;
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (++i < len)
		dest[i] = s[i + start];
	dest[i] = '\0';
	return (dest);
}
