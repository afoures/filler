/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:06:24 by marvin            #+#    #+#             */
/*   Updated: 2018/01/29 12:13:00 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

intmax_t	*pf_arg_n_z(va_list ap)
{
	intmax_t	*nb;

	nb = (intmax_t *)va_arg(ap, size_t *);
	return (nb);
}
