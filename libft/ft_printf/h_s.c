/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:09:58 by afoures           #+#    #+#             */
/*   Updated: 2018/02/06 16:24:01 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int			pf_h_s(va_list ap, t_flags *f)
{
	char	*str;
	char	c;

	f->ok = 1;
	if (f->modifier == l)
		return (pf_h_ss(ap, f));
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	pf_get_strlen(str, f);
	c = ' ' + 16 * (f->zero);
	f->width = (f->width - f->len) * (f->width - f->len > 0);
	if (!f->minus)
	{
		if (f->width && pf_put_width(c, f->width, f) < 0)
			return (-1);
		pf_put_buf(f->fd, str, f->len, 1);
	}
	else
	{
		pf_put_buf(f->fd, str, f->len, 1);
		if (f->width && pf_put_width(c, f->width, f) < 0)
			return (-1);
	}
	return (f->width + f->len);
}

int			pf_h_ss(va_list ap, t_flags *f)
{
	wchar_t	*str;
	char	c;

	f->ok = 1;
	if (!(str = va_arg(ap, wchar_t *)))
		str = L"(null)";
	pf_get_wstrlen(str, f);
	c = ' ' + 16 * (f->zero);
	f->width = (f->width - f->precision) * (f->width - f->precision > 0);
	if (!f->minus)
	{
		if ((f->width && pf_put_width(c, f->width, f) < 0)
		| (pf_put_wstr(str, f) < 0))
			return (-1);
	}
	else
	{
		if ((pf_put_wstr(str, f) < 0)
		| (f->width && pf_put_width(c, f->width, f) < 0))
			return (-1);
	}
	return (f->width + f->precision);
}
