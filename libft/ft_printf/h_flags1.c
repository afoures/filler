/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_flags1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:28:44 by afoures           #+#    #+#             */
/*   Updated: 2018/02/17 16:43:38 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		pf_h_apostrophe(va_list ap, t_flags *f)
{
	(void)ap;
	f->apostrophe = *nl_langinfo(THOUSEP);
	return (0);
}

int		pf_h_wildcard(va_list ap, t_flags *f)
{
	f->width = va_arg(ap, int);
	if (f->width < 0)
	{
		f->width = -f->width;
		f->minus = 1;
	}
	f->c_width = f->width;
	return (0);
}

int		pf_h_width(va_list ap, t_flags *f, unsigned char **fmt)
{
	(void)ap;
	f->width = 0;
	while (*fmt && **fmt >= '0' && **fmt <= '9')
	{
		f->width = f->width * 10 + **fmt - 48;
		(*fmt)++;
	}
	(*fmt)--;
	f->c_width = f->width;
	return (0);
}

int		pf_h_precision(va_list ap, t_flags *f, unsigned char **fmt)
{
	f->precision = 0;
	f->c_prec = 1;
	(*fmt)++;
	if (**fmt == '*')
	{
		f->precision = va_arg(ap, int);
		if (f->precision < 0)
		{
			f->precision = -1;
			f->c_prec = 0;
		}
		return (0);
	}
	while (**fmt && **fmt >= '0' && **fmt <= '9')
	{
		f->precision = f->precision * 10 + **fmt - 48;
		(*fmt)++;
	}
	(*fmt)--;
	return (0);
}
