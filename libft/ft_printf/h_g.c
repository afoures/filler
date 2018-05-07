/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_g.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 18:41:08 by marvin            #+#    #+#             */
/*   Updated: 2018/02/17 16:09:12 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int			pf_h_g(va_list ap, t_flags *f)
{
	long double	nb;
	long double	tmp;
	int			e;

	f->precision += (f->precision == 0) + (7 * !f->c_prec);
	nb = pf_float_conversion(ap, f);
	if (nb == INFINITY || nb == -INFINITY || !(nb == nb))
		return (pf_h_f_nanorinf(nb, f));
	tmp = nb;
	e = pf_e_change(&tmp, f, 1);
	if (e < -4 || e >= f->precision)
		return (pf_h_eg(f, nb));
	return (pf_h_fg(f, nb));
}

int			pf_h_gg(va_list ap, t_flags *f)
{
	long double	nb;
	long double	tmp;
	int			e;

	f->precision += (f->precision == 0) + (7 * !f->c_prec);
	nb = pf_float_conversion(ap, f);
	if (nb == INFINITY || nb == -INFINITY || !(nb == nb))
		return (pf_h_ff_nanorinf(nb, f));
	tmp = nb;
	e = pf_e_change(&tmp, f, 1);
	if (e < -4 || e >= f->precision)
		return (pf_h_eeg(f, nb));
	return (pf_h_ffg(f, nb));
}
