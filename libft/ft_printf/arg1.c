/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:52:21 by afoures           #+#    #+#             */
/*   Updated: 2018/01/06 16:48:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

intmax_t	pf_arg_d_none(va_list ap)
{
	intmax_t	nb;

	nb = va_arg(ap, int);
	return (nb);
}

intmax_t	pf_arg_d_hh(va_list ap)
{
	intmax_t	nb;
	char		c;

	c = va_arg(ap, int);
	nb = c;
	return (nb);
}

intmax_t	pf_arg_d_h(va_list ap)
{
	intmax_t	nb;
	short int	s;

	s = va_arg(ap, int);
	nb = s;
	return (nb);
}

intmax_t	pf_arg_d_ll(va_list ap)
{
	intmax_t	nb;

	nb = va_arg(ap, long long int);
	return (nb);
}

intmax_t	pf_arg_d_l(va_list ap)
{
	intmax_t	nb;

	nb = va_arg(ap, long int);
	return (nb);
}
