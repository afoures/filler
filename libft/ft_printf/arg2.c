/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:52:29 by afoures           #+#    #+#             */
/*   Updated: 2018/01/06 16:46:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

intmax_t	pf_arg_d_j(va_list ap)
{
	intmax_t	nb;

	nb = va_arg(ap, intmax_t);
	return (nb);
}

intmax_t	pf_arg_d_z(va_list ap)
{
	intmax_t	nb;

	nb = va_arg(ap, size_t);
	return (nb);
}

uintmax_t	pf_arg_v_none(va_list ap)
{
	uintmax_t	nb;

	nb = va_arg(ap, unsigned int);
	return (nb);
}

uintmax_t	pf_arg_v_hh(va_list ap)
{
	uintmax_t		nb;
	unsigned char	c;

	c = va_arg(ap, unsigned int);
	nb = c;
	return (nb);
}

uintmax_t	pf_arg_v_h(va_list ap)
{
	uintmax_t			nb;
	unsigned short int	s;

	s = va_arg(ap, unsigned int);
	nb = s;
	return (nb);
}
