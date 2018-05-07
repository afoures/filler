/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:31:07 by afoures           #+#    #+#             */
/*   Updated: 2017/11/10 15:02:44 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	size_t	len;
	size_t	nb;
	size_t	sign;
	char	*result;

	sign = (n < 0) ? 1 : 0;
	if (n == -2147483648)
		return (ft_strcpy(ft_strnew(11), "-2147483648"));
	len = ft_intlen(n);
	if (n == 0)
		return (ft_memset(ft_strnew(1), '0', 1));
	nb = (n < 0) ? -n : n;
	if (!(result = ft_strnew(len)))
		return (NULL);
	while (len > sign)
	{
		result[len - 1] = (nb % 10) + 48;
		nb /= 10;
		len--;
	}
	if (sign == 1)
		result[0] = '-';
	return (result);
}
