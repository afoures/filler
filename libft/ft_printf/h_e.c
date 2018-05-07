/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_e.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 22:20:11 by marvin            #+#    #+#             */
/*   Updated: 2018/02/17 18:07:22 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int			pf_e_change(long double *nb, t_flags *f, int g)
{
	int		e;

	e = 0;
	while (*nb != 0 && (*nb < -10 || *nb > 10) && ++e)
		*nb /= 10;
	while (*nb != 0 && *nb > -1 && *nb < 1 && --e)
		*nb *= 10;
	if (!g)
	{
		f->e_len += 1 + (e >= 100 || e <= -100) + (e >= 1000 || e <= -1000);
		if (f->zero && f->width != -1
			&& f->width > f->len + f->precision + 2 + f->e_len)
		{
			f->len = f->width - 2 - f->e_len - f->precision
					- (f->precision > 0 || f->hashtag);
			f->width = 0;
		}
		f->zero += f->zero;
		f->width = (f->width - f->len - 2 - f->e_len - f->precision
		- (f->precision > 0 || f->hashtag)) * (f->width - f->len - 2
		- f->e_len - f->precision - (f->precision > 0 || f->hashtag) > 0);
	}
	return (e);
}

int			pf_h_e(va_list ap, t_flags *f)
{
	long double	nb;
	int			e;

	nb = pf_float_conversion(ap, f);
	f->ok = 1;
	if (nb == INFINITY || nb == -INFINITY || !(nb == nb))
		return (pf_h_f_nanorinf(nb, f));
	pf_get_efloatlen(nb, f);
	e = pf_e_change(&nb, f, 0);
	if (!f->minus)
	{
		if ((f->width && pf_put_width(' ', f->width, f) < 0)
		| (pf_efloat_toa(nb, f, e, 0) < 0))
			return (-1);
	}
	else
	{
		if ((pf_efloat_toa(nb, f, e, 0) < 0)
		| (f->width && pf_put_width(' ', f->width, f) < 0))
			return (-1);
	}
	return (f->width + f->len + f->precision + (1 * (f->precision > 0
			|| f->hashtag)) + 2 + f->e_len);
}

int			pf_h_ee(va_list ap, t_flags *f)
{
	long double	nb;
	int			e;

	nb = pf_float_conversion(ap, f);
	f->ok = 1;
	if (nb == INFINITY || nb == -INFINITY || !(nb == nb))
		return (pf_h_ff_nanorinf(nb, f));
	pf_get_efloatlen(nb, f);
	e = pf_e_change(&nb, f, 0);
	if (!f->minus)
	{
		if ((f->width && pf_put_width(' ', f->width, f) < 0)
		| (pf_efloat_toa(nb, f, e, 1) < 0))
			return (-1);
	}
	else
	{
		if ((pf_efloat_toa(nb, f, e, 1) < 0)
		| (f->width && pf_put_width(' ', f->width, f) < 0))
			return (-1);
	}
	return (f->width + f->len + f->precision + (1 * (f->precision > 0
			|| f->hashtag)) + 2 + f->e_len);
}

int			pf_h_eg(t_flags *f, long double nb)
{
	int		e;

	f->ok = 1;
	pf_get_efloatlen(nb, f);
	f->precision -= f->precision * (nb == 0. && !f->hashtag);
	f->precision -= 1;
	f->precision *= (f->precision > 0);
	e = pf_e_change(&nb, f, 0);
	f->p = 1;
	if (!f->minus)
	{
		if ((f->width && pf_put_width(' ', f->width, f) < 0)
		| (pf_ge_float_toa(nb, f, e, 0) < 0))
			return (-1);
	}
	else
	{
		if ((pf_ge_float_toa(nb, f, e, 0) < 0)
		| (f->width && pf_put_width(' ', f->width, f) < 0))
			return (-1);
	}
	return (f->width + f->len + f->precision + (f->precision > f->rm_zero
		|| f->hashtag || (nb == 0. && !f->c_prec)) + 2 + f->e_len + f->rm_zero);
}

int			pf_h_eeg(t_flags *f, long double nb)
{
	int		e;

	f->ok = 1;
	pf_get_efloatlen(nb, f);
	f->precision -= f->precision * (nb == 0. && !f->hashtag);
	f->precision -= 1;
	f->precision *= (f->precision > 0);
	e = pf_e_change(&nb, f, 0);
	f->p = 1;
	if (!f->minus)
	{
		if ((f->width && pf_put_width(' ', f->width, f) < 0)
		| (pf_ge_float_toa(nb, f, e, 1) < 0))
			return (-1);
	}
	else
	{
		if ((pf_ge_float_toa(nb, f, e, 1) < 0)
		| (f->width && pf_put_width(' ', f->width, f) < 0))
			return (-1);
	}
	return (f->width + f->len + f->precision + (f->precision > f->rm_zero
		|| f->hashtag || (nb == 0. && !f->c_prec)) + 2 + f->e_len + f->rm_zero);
}
