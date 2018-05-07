/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 18:39:26 by marvin            #+#    #+#             */
/*   Updated: 2018/02/17 17:26:00 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int			pf_a_change(long double *nb, t_flags *f)
{
	int		e;

	e = (f->modifier == L && *nb != 0) * (-2 + (*nb > -1 && *nb < 1) * -2);
	*nb *= 1 + ((f->modifier == L) * (3 + (*nb > -1 && *nb < 1) * 12));
	while (*nb != 0 && (*nb < -2 + (f->modifier == L) * -14
			|| *nb > 2 + (f->modifier == L) * 14) && (++e >= INT_MIN))
		*nb /= 2;
	while (*nb != 0 && *nb > -1 + (f->modifier == L) * -7
			&& *nb < 1 + (f->modifier == L) * 7 && (--e >= INT_MIN))
		*nb *= 2;
	f->e_len += (e >= 100 || e <= -100) + (e >= 10 || e <= -10) + (e >= 1000
			|| e <= -1000) + (e >= 10000 || e <= -10000);
	if (f->zero && f->width != -1
		&& f->width > f->len + f->precision + 2 + f->e_len)
	{
		f->len = f->width - 2 - f->e_len - f->precision - (f->precision > 0
					|| f->hashtag);
		f->width = 0;
		f->zero = 2;
	}
	f->width = (f->width - f->len - 2 - f->e_len - f->precision
	- (f->precision > 0 || f->hashtag)) * (f->width - f->len - 2 - f->e_len
	- f->precision - (f->precision > 0 || f->hashtag) > 0);
	return (e);
}

int			pf_h_a(va_list ap, t_flags *f)
{
	long double	nb;
	int			e;

	nb = pf_float_conversion(ap, f);
	f->ok = 1;
	f->b_len = 16;
	if (nb == INFINITY || nb == -INFINITY || !(nb == nb))
		return (pf_h_f_nanorinf(nb, f));
	pf_get_afloatlen(nb, f);
	e = pf_a_change(&nb, f);
	if (!f->minus)
	{
		if ((f->width && pf_put_width(' ', f->width, f) < 0)
		| (pf_afloat_toa(nb, f, e, 0) < 0))
			return (-1);
	}
	else
	{
		if ((pf_afloat_toa(nb, f, e, 0) < 0)
		| (f->width && pf_put_width(' ', f->width, f) < 0))
			return (-1);
	}
	return (f->width + f->len + f->precision + (f->precision > f->rm_zero
		|| f->hashtag || (nb == 0. && !f->c_prec)) + 2 + f->e_len + f->rm_zero);
}

int			pf_h_aa(va_list ap, t_flags *f)
{
	long double	nb;
	int			e;

	nb = pf_float_conversion(ap, f);
	f->ok = 1;
	f->b_len = 16;
	f->p = 1;
	if (nb == INFINITY || nb == -INFINITY || !(nb == nb))
		return (pf_h_ff_nanorinf(nb, f));
	pf_get_afloatlen(nb, f);
	e = pf_a_change(&nb, f);
	if (!f->minus)
	{
		if ((f->width && pf_put_width(' ', f->width, f) < 0)
		| (pf_afloat_toa(nb, f, e, 1) < 0))
			return (-1);
	}
	else
	{
		if ((pf_afloat_toa(nb, f, e, 1) < 0)
		| (f->width && pf_put_width(' ', f->width, f) < 0))
			return (-1);
	}
	return (f->width + f->len + f->precision + (f->precision > f->rm_zero
		|| f->hashtag || (nb == 0. && !f->c_prec)) + 2 + f->e_len + f->rm_zero);
}
