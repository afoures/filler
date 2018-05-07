/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_u.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:24:33 by afoures           #+#    #+#             */
/*   Updated: 2018/01/29 12:08:35 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int			pf_h_u(va_list ap, t_flags *f)
{
	uintmax_t	nb;
	uintmax_t	(*pf_arg_v[8])(va_list ap);

	pf_init_arg_v(pf_arg_v);
	nb = pf_arg_v[(int)f->modifier](ap);
	pf_get_uintlen(nb, f);
	f->width = (f->width - f->len) * (f->width - f->len > 0);
	if (!f->minus)
	{
		if ((f->width && pf_put_width(' ', f->width, f) < 0)
		| (pf_uint_toa(nb, "0123456789", f) < 0))
			return (-1);
	}
	else
	{
		if ((pf_uint_toa(nb, "0123456789", f) < 0) | (f->width
		&& pf_put_width(' ', f->width, f) < 0))
			return (-1);
	}
	f->ok = 1;
	return (f->width + f->len);
}

void		pf_init_arg_v(uintmax_t (*pf_arg_v[8])(va_list ap))
{
	pf_arg_v[0] = pf_arg_v_none;
	pf_arg_v[1] = pf_arg_v_hh;
	pf_arg_v[2] = pf_arg_v_h;
	pf_arg_v[3] = pf_arg_v_ll;
	pf_arg_v[4] = pf_arg_v_l;
	pf_arg_v[5] = pf_arg_v_j;
	pf_arg_v[6] = pf_arg_v_z;
	pf_arg_v[7] = pf_arg_v_none;
}

int			pf_h_uu(va_list ap, t_flags *f)
{
	f->modifier = l;
	return (pf_h_u(ap, f));
}
