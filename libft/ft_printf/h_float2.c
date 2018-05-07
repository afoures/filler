/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_float2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:31:52 by afoures           #+#    #+#             */
/*   Updated: 2018/03/05 10:14:48 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int			pf_m_ll(va_list ap, t_flags *f)
{
	(void)ap;
	f->modifier = L;
	return (0);
}

long double	pf_float_conversion(va_list ap, t_flags *f)
{
	if (f->modifier == L)
		return (va_arg(ap, long double));
	return ((long double)va_arg(ap, double));
}

void		pf_float_integral(char *str, intmax_t nbr, int *tmp, t_flags *f)
{
	int		i;
	char	*base;

	i = 0;
	base = pf_create_base(f->p);
	while (nbr || *tmp)
	{
		if ((i % 3) == 0 && i > 0 && f->apostrophe)
		{
			str[*tmp - 1] = f->apostrophe;
			i = 0;
		}
		else
		{
			str[*tmp - 1] = base[(nbr > 0 ? nbr : -nbr) % f->b_len];
			nbr /= f->b_len;
			i++;
		}
		(*tmp)--;
	}
}

int			pf_get_efloatlen(long double nb, t_flags *f)
{
	f->len = 1 + ((nb < 0 || ((f->plus || f->space)
					&& (f->precision || f->c_prec))) && f->width);
	if (f->precision < 0)
		f->precision = 6;
	return (1);
}
