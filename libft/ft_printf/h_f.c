/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_f.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:42:07 by afoures           #+#    #+#             */
/*   Updated: 2018/03/04 00:32:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int			pf_h_f(va_list ap, t_flags *f)
{
	long double	nb;

	nb = pf_float_conversion(ap, f);
	f->ok = 1;
	if (nb == INFINITY || nb == -INFINITY || !(nb == nb))
		return (pf_h_f_nanorinf(nb, f));
	pf_get_floatlen(nb, f);
	if (!f->minus)
	{
		if ((f->width && pf_put_width(' ', f->width, f) < 0)
		| (pf_float_toa(nb, f) < 0))
			return (-1);
	}
	else
	{
		if ((pf_float_toa(nb, f) < 0)
		| (f->width && pf_put_width(' ', f->width, f) < 0))
			return (-1);
	}
	return (f->width + f->len + f->precision
			+ (f->precision > 0 || f->hashtag));
}

int			pf_h_ff(va_list ap, t_flags *f)
{
	long double	nb;

	nb = pf_float_conversion(ap, f);
	f->ok = 1;
	if (nb == INFINITY || nb == -INFINITY || !(nb == nb))
		return (pf_h_ff_nanorinf(nb, f));
	pf_get_floatlen(nb, f);
	if (!f->minus)
	{
		if ((f->width && pf_put_width(' ', f->width, f) < 0)
		| (pf_float_toa(nb, f) < 0))
			return (-1);
	}
	else
	{
		if ((pf_float_toa(nb, f) < 0)
		| (f->width && pf_put_width(' ', f->width, f) < 0))
			return (-1);
	}
	return (f->width + f->len + f->precision
			+ (f->precision > 0 || f->hashtag));
}

int			pf_h_fg(t_flags *f, long double nb)
{
	f->ok = 1;
	f->precision -= f->precision * (nb == 0. && !f->hashtag);
	pf_get_gfloatlen(nb, f);
	if (!f->minus)
	{
		if ((f->width && pf_put_width(' ', f->width, f) < 0)
		| (pf_gf_float_toa(nb, f) < 0))
			return (-1);
	}
	else
	{
		if ((pf_gf_float_toa(nb, f) < 0)
		| (f->width && pf_put_width(' ', f->width, f) < 0))
			return (-1);
	}
	return (f->width + f->len + f->precision
		+ (f->precision > f->rm_zero || f->hashtag || nb == 0.) + f->rm_zero);
}

int			pf_h_ffg(t_flags *f, long double nb)
{
	f->ok = 1;
	f->precision -= f->precision * (nb == 0. && !f->hashtag);
	pf_get_gfloatlen(nb, f);
	if (!f->minus)
	{
		if ((f->width && pf_put_width(' ', f->width, f) < 0)
		| (pf_gf_float_toa(nb, f) < 0))
			return (-1);
	}
	else
	{
		if ((pf_gf_float_toa(nb, f) < 0)
		| (f->width && pf_put_width(' ', f->width, f) < 0))
			return (-1);
	}
	return (f->width + f->len + f->precision
		+ (f->precision > f->rm_zero || f->hashtag || nb == 0.) + f->rm_zero);
}
