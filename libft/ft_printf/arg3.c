/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:52:37 by afoures           #+#    #+#             */
/*   Updated: 2018/01/06 16:48:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

uintmax_t	pf_arg_v_ll(va_list ap)
{
	uintmax_t	nb;

	nb = va_arg(ap, unsigned long long int);
	return (nb);
}

uintmax_t	pf_arg_v_l(va_list ap)
{
	uintmax_t	nb;

	nb = va_arg(ap, unsigned long int);
	return (nb);
}

uintmax_t	pf_arg_v_j(va_list ap)
{
	uintmax_t	nb;

	nb = va_arg(ap, uintmax_t);
	return (nb);
}

uintmax_t	pf_arg_v_z(va_list ap)
{
	uintmax_t	nb;

	nb = va_arg(ap, size_t);
	return (nb);
}

intmax_t	*pf_arg_n_none(va_list ap)
{
	intmax_t	*nb;

	nb = (intmax_t *)va_arg(ap, int *);
	return (nb);
}
