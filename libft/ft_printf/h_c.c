/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_c.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:15:21 by afoures           #+#    #+#             */
/*   Updated: 2018/02/06 16:13:56 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int			pf_h_c(va_list ap, t_flags *f)
{
	char		c;
	char		s;

	if (f->modifier == l)
		return (pf_h_cc(ap, f));
	s = va_arg(ap, int);
	c = ' ' + 16 * (f->zero);
	f->width = (f->width - f->len) * (f->width - f->len > 0);
	if (!f->minus)
	{
		if (f->width && pf_put_width(c, f->width, f) < 0)
			return (-1);
		pf_put_buf(f->fd, &s, 1, 1);
	}
	else
	{
		pf_put_buf(f->fd, &s, 1, 1);
		if (f->width && pf_put_width(c, f->width, f) < 0)
			return (-1);
	}
	f->ok = 1;
	return (f->width + f->len);
}

int			pf_h_cc(va_list ap, t_flags *f)
{
	char		c;
	wchar_t		s;

	s = va_arg(ap, wchar_t);
	if (s < 0 || s > 0x10ffff || (s >= 0xd800 && s <= 0xdfff)
			|| (MB_CUR_MAX == 1 && s > 255))
		return (-1);
	c = ' ' + 16 * (f->zero);
	pf_get_wclen(s, f);
	f->width = (f->width - f->len) * (f->width - f->len > 0);
	if (!f->minus)
	{
		if (f->width && pf_put_width(c, f->width, f) < 0)
			return (-1);
		pf_put_wchar_t(s, f, 1);
	}
	else
	{
		pf_put_wchar_t(s, f, 1);
		if (f->width && pf_put_width(c, f->width, f) < 0)
			return (-1);
	}
	f->ok = 1;
	return (f->width + f->len);
}
