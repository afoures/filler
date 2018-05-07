/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_m.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:30:48 by afoures           #+#    #+#             */
/*   Updated: 2018/02/04 22:53:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

void	put_memory(const unsigned char *adr, char *s, char *base, t_flags *f)
{
	int					i;
	int					skp;
	char				*tmp;

	i = 0;
	tmp = s;
	skp = 0;
	while (i < f->len || (i % (f->width * f->precision) == 0))
	{
		if (i && i % (f->width * f->precision) == 0 && (skp == 0) && (skp = 1))
			*s = '\n';
		else if (i && i % f->precision == 0 && (skp == 0) && (skp = 1))
			*s = ' ';
		else
		{
			*(s++) = base[((int)*adr / 16) % 16];
			*s = base[(int)*(adr++) % 16];
			i++;
			skp = 0;
		}
		s++;
	}
	i = 1 * ((f->len * 2) % f->precision == 0);
	pf_put_buf(f->fd, tmp, f->len * 2 + f->len / f->precision - i, 1);
	free(tmp);
}

int		pf_h_m(va_list ap, t_flags *f)
{
	const unsigned char	*adr;
	char				*s;

	f->width += !f->c_width * 9 + (f->width == 0) * 8;
	f->precision += !f->c_prec * 3 + (f->precision == 0) * 2;
	f->precision += (f->precision + f->width == 2) * 1;
	adr = va_arg(ap, unsigned char *);
	f->len = va_arg(ap, int);
	f->ok = 1;
	if (!(s = malloc(sizeof(*s) * (f->len * 2 + f->len / f->precision) + 1)))
		return (pf_put_error("malloc error\n", 13));
	put_memory(adr, s, "0123456789abcdef", f);
	return (f->len * 2 + f->len / f->precision - 1);
}

int		pf_h_mm(va_list ap, t_flags *f)
{
	const unsigned char	*adr;
	char				*s;

	f->width += !f->c_width * 9 + (f->width == 0) * 8;
	f->precision += !f->c_prec * 3 + (f->precision == 0) * 2;
	f->precision += (f->precision + f->width == 2) * 1;
	adr = va_arg(ap, unsigned char *);
	f->len = va_arg(ap, int);
	f->ok = 1;
	if (!(s = malloc(sizeof(*s) * (f->len * 2 + f->len / f->precision) + 1)))
		return (pf_put_error("malloc error\n", 13));
	put_memory(adr, s, "0123456789ABCDEF", f);
	return (f->len * 2 + f->len / f->precision);
}
