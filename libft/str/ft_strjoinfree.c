/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:12:42 by afoures           #+#    #+#             */
/*   Updated: 2017/11/09 18:35:55 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2, int n)
{
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(res = (char *)malloc(sizeof(char) *
			(ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1)))
		return (NULL);
	res = ft_strcpy(res, (char *)s1);
	res = ft_strcat(res, (char *)s2);
	if (n == 1 || n == 3)
		ft_strdel((char **)&s1);
	if (n == 2 || n == 3)
		ft_strdel((char **)&s2);
	return (res);
}
