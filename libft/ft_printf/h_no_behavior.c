/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_no_behavior.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 19:48:16 by marvin            #+#    #+#             */
/*   Updated: 2018/03/05 10:41:13 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		pf_no_behavior(va_list ap, t_flags *f, unsigned char **fmt)
{
	char	c;

	(void)ap;
	f->width -= f->len;
	f->width *= (f->width > 0);
	c = ' ' + 16 * (f->zero);
	if (!f->minus)
	{
		if (f->width)
			pf_put_width(c, f->width, f);
		pf_put_buf(f->fd, *fmt, 1, 1);
	}
	else
	{
		pf_put_buf(f->fd, *fmt, 1, 1);
		if (f->width)
			pf_put_width(c, f->width, f);
	}
	f->ok = 1;
	return (f->width + f->len);
}

int		pf_h_null(va_list ap, t_flags *f)
{
	(void)ap;
	f->ok = 1;
	return (0);
}
