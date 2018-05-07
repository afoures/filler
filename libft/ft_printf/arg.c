/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:06:14 by afoures           #+#    #+#             */
/*   Updated: 2018/01/26 16:07:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

intmax_t	*pf_arg_n_hh(va_list ap)
{
	intmax_t	*nb;

	nb = (intmax_t *)va_arg(ap, char *);
	return (nb);
}

intmax_t	*pf_arg_n_h(va_list ap)
{
	intmax_t	*nb;

	nb = (intmax_t *)va_arg(ap, short int *);
	return (nb);
}

intmax_t	*pf_arg_n_ll(va_list ap)
{
	intmax_t	*nb;

	nb = (intmax_t *)va_arg(ap, long long int *);
	return (nb);
}

intmax_t	*pf_arg_n_l(va_list ap)
{
	intmax_t	*nb;

	nb = va_arg(ap, long int *);
	return (nb);
}

intmax_t	*pf_arg_n_j(va_list ap)
{
	intmax_t	*nb;

	nb = va_arg(ap, intmax_t *);
	return (nb);
}
