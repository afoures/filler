/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:18:04 by afoures           #+#    #+#             */
/*   Updated: 2018/01/29 12:21:07 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		pf_h_d(va_list ap, t_flags *f)
{
	intmax_t	nb;
	intmax_t	(*pf_arg_d[8])(va_list);

	pf_init_arg_d(pf_arg_d);
	nb = pf_arg_d[(int)f->modifier](ap);
	pf_get_intlen(nb, f);
	f->width = (f->width - f->len) * (f->width - f->len > 0);
	if (!f->minus)
	{
		if ((f->width && pf_put_width(' ', f->width, f) < 0)
		| (pf_int_toa(nb, f) < 0))
			return (-1);
	}
	else
	{
		if ((pf_int_toa(nb, f) < 0)
		| (f->width && pf_put_width(' ', f->width, f) < 0))
			return (-1);
	}
	f->ok = 1;
	return (f->width + f->len);
}

void	pf_init_arg_d(intmax_t (*pf_arg_d[8])(va_list ap))
{
	pf_arg_d[0] = pf_arg_d_none;
	pf_arg_d[1] = pf_arg_d_hh;
	pf_arg_d[2] = pf_arg_d_h;
	pf_arg_d[3] = pf_arg_d_ll;
	pf_arg_d[4] = pf_arg_d_l;
	pf_arg_d[5] = pf_arg_d_j;
	pf_arg_d[6] = pf_arg_d_z;
	pf_arg_d[7] = pf_arg_d_none;
}

int		pf_h_dd(va_list ap, t_flags *f)
{
	f->modifier = l;
	return (pf_h_d(ap, f));
}
