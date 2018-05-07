/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_o.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:44:21 by afoures           #+#    #+#             */
/*   Updated: 2018/01/14 21:27:23 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int			pf_h_o(va_list ap, t_flags *f)
{
	uintmax_t	nb;
	uintmax_t	(*pf_arg_v[8])(va_list ap);

	f->b_len = 8;
	pf_init_arg_v(pf_arg_v);
	nb = pf_arg_v[(int)f->modifier](ap);
	pf_get_uintlen(nb, f);
	f->width = (f->width - f->len) * (f->width - f->len > 0);
	if (!f->minus)
	{
		if ((f->width && pf_put_width(' ', f->width, f) < 0)
		| (pf_uint_toa(nb, "012345678", f) < 0))
			return (-1);
	}
	else
	{
		if ((pf_uint_toa(nb, "012345678", f) < 0) | (f->width
		&& pf_put_width(' ', f->width, f) < 0))
			return (-1);
	}
	f->ok = 1;
	return (f->width + f->len);
}

int			pf_h_oo(va_list ap, t_flags *f)
{
	f->modifier = l;
	return (pf_h_o(ap, f));
}
