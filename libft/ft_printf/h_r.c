/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_r.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 22:24:55 by afoures           #+#    #+#             */
/*   Updated: 2018/02/04 22:53:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		pf_put_nprint_c(unsigned char *str2, unsigned char *str, char *base)
{
	int nb;

	nb = (int)*str;
	str2[0] = '\\';
	str2[1] = '0';
	str2[2] = 'x';
	str2[3] = base[(nb / 16) % 16];
	str2[4] = base[nb % 16];
	return (5);
}

int		pf_put_nprint(unsigned char *str, char *base, t_flags *f)
{
	unsigned char	*str2;
	int				i;
	int				j;

	if (!(str2 = malloc(sizeof(*str2) * (f->len * 4) + 1)))
		return (pf_put_error("malloc error\n", 13));
	i = 0;
	j = -1;
	while (++j < f->len && f->precision)
	{
		if (f->precision > 0 && f->precision < i + 1)
			break ;
		if ((int)str[j] < 32)
		{
			if (f->precision > 0 && f->precision <= i + 5)
				break ;
			i += pf_put_nprint_c(str2 + i, str + j, base);
		}
		else
			str2[i++] = str[j];
	}
	pf_put_buf(f->fd, str2, i, 1);
	free(str2);
	return (i);
}

int		pf_h_r(va_list ap, t_flags *f)
{
	char			c;
	unsigned char	*str;

	f->len = va_arg(ap, int);
	str = va_arg(ap, unsigned char *);
	c = ' ' + 16 * (f->zero);
	if (f->len < 0)
		return (-1);
	f->width = (f->width - f->len) * (f->width - f->len > 0);
	if (!f->minus)
	{
		if ((f->width && pf_put_width(c, f->width, f) < 0)
		| ((f->len = pf_put_nprint(str, "0123456789abcdef", f)) < 0))
			return (-1);
	}
	else
	{
		if (((f->len = pf_put_nprint(str, "0123456789abcdef", f)) < 0)
		| (f->width && pf_put_width(c, f->width, f) < 0))
			return (-1);
	}
	f->ok = 1;
	return (f->width + f->len);
}
