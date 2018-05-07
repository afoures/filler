/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:10:56 by afoures           #+#    #+#             */
/*   Updated: 2018/03/05 10:14:57 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		pf_get_intlen(intmax_t nb, t_flags *f)
{
	intmax_t	tmp;

	tmp = nb;
	f->len = 0;
	if (f->precision != -1)
		f->zero = 0;
	while (nb && ++f->len)
		nb /= f->b_len;
	f->len += (tmp == 0 && f->precision != 0);
	nb = tmp;
	if (f->apostrophe)
		while (nb > 999 && ++f->len)
			nb /= 1000;
	if (f->zero && f->width != -1 && f->precision == -1 && f->width > f->len)
	{
		f->precision = f->width;
		f->width = 0;
	}
	if (f->precision > f->len)
		f->len = f->precision;
	f->len += ((tmp < 0 || ((f->plus || f->space)
				&& (f->precision || f->c_prec))) && f->width);
	return (f->len);
}

int		pf_get_uintlen(uintmax_t nb, t_flags *f)
{
	uintmax_t	tmp;

	tmp = nb;
	f->len = 0;
	while (nb && ++f->len)
		nb /= f->b_len;
	f->zero -= (f->precision != -1);
	if (f->zero && f->width != -1 && f->precision == -1 && f->width > f->len)
	{
		f->precision = f->width;
		f->width = 0;
	}
	f->len += ((f->hashtag && f->b_len == 8)
				|| (tmp == 0 && f->precision != 0));
	f->len += 2 * (f->hashtag && f->b_len == 16 && tmp > 0 && !f->p
				&& (f->c_width && f->width == 0));
	nb = tmp;
	if (f->apostrophe)
		while (nb > (uintmax_t)(f->b_len * f->b_len * f->b_len) - 1 && ++f->len)
			nb /= (f->b_len * f->b_len * f->b_len);
	f->len += (f->precision - f->len) * (f->precision > f->len);
	f->len += 2 * (f->hashtag && f->b_len == 16 && (tmp > 0
				|| (tmp == 0 && f->p)) && f->width);
	return (f->len);
}

int		pf_get_afloatlen(long double nb, t_flags *f)
{
	f->len = 3 + ((nb < 0 || ((f->plus || f->space)
					&& (f->precision || f->c_prec))) && f->width);
	if (!f->c_prec)
	{
		if ((nb - (intmax_t)nb) == 0)
		{
			f->precision = 0;
			if (!((intmax_t)nb > -16 && (intmax_t)nb < 16))
				while ((intmax_t)nb && ++f->precision != -1)
					nb /= 16;
		}
		else
			f->precision = 13 + 2 * (f->modifier == L);
	}
	return (1);
}

int		pf_get_floatlen(long double nb, t_flags *f)
{
	intmax_t	n;

	n = nb;
	f->len = 0;
	while (n && ++f->len)
		n /= 10;
	if (f->precision < 0)
		f->precision = 6;
	f->len += ((intmax_t)nb == 0);
	f->len += ((nb < 0 || ((f->plus || f->space)
				&& (f->precision || f->c_prec))) && f->width);
	n = nb;
	while (f->apostrophe && n > 999 && ++f->len)
		n /= 1000;
	if (f->zero && f->width != -1 && f->width > f->len + f->precision)
	{
		f->len = f->width - f->precision - (f->precision > 0
			|| f->hashtag);
		f->width = 0;
	}
	f->width = (f->width - f->len - f->precision - (f->precision > 0
			|| f->hashtag)) * (f->width - f->len - f->precision
			- (f->precision > 0 || f->hashtag) > 0);
	return (f->len);
}

int		pf_get_gfloatlen(long double nb, t_flags *f)
{
	intmax_t	n;

	n = nb;
	f->len = 0;
	while (n && ++f->len)
		n /= 10;
	f->len += ((int)nb == 0);
	f->len += ((nb < 0 || ((f->plus || f->space)
				&& (f->precision || nb == 0. || f->c_prec))) && f->width);
	f->precision -= f->len - ((nb < 0 || ((f->plus || f->space)
				&& (f->precision || f->c_prec))) && f->width);
	f->precision *= (f->precision > 0);
	while (f->apostrophe && n > 999 && ++f->len)
		n /= 1000;
	if (f->zero && f->width != -1 && f->width > f->len + f->precision)
	{
		f->len = f->width - f->precision - (f->precision > 0
			|| f->hashtag);
		f->width = 0;
	}
	f->zero = 2 * f->zero * (f->zero < 2);
	f->width = (f->width - f->len - f->precision - (f->precision > 0
			|| f->hashtag)) * (f->width - f->len - f->precision
			- (f->precision > 0 || f->hashtag) > 0);
	return (f->len);
}
