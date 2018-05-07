/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:47:56 by afoures           #+#    #+#             */
/*   Updated: 2018/03/04 01:46:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

void	pf_decimal(char *str, long double nbr, int tmp, t_flags *f)
{
	while (tmp < f->precision + 1)
	{
		nbr = (nbr - (intmax_t)nbr) * 10 * (-2 * (nbr < 0) + 1);
		str[f->len + tmp + 1] = (intmax_t)nbr + '0';
		tmp++;
	}
}

void	pf_adecimal(char *str, long double nbr, int tmp, t_flags *f)
{
	char	*base;

	base = pf_create_base(f->p);
	while (tmp < f->precision + 1)
	{
		nbr = (nbr - (intmax_t)nbr) * 16 * (-2 * (nbr < 0) + 1);
		str[f->len + tmp + 1] = base[(int)nbr % 16];
		tmp++;
	}
}

void	add_zero(int len, char *str, t_flags *f, int neg)
{
	int		stop;
	int		start;
	int		i;

	stop = (f->b_len == 16) * 2 + (neg & 1 || f->plus || f->space);
	start = f->len + f->precision;
	while (start >= stop)
	{
		str[start + len] = str[start];
		start--;
	}
	i = 0;
	while (i < len)
	{
		str[stop + i] = '0';
		i++;
	}
	f->len += len;
}

int		pf_rm_zero(char *str, t_flags *f, char *first, int neg)
{
	int		len;

	while (*str == '0' && --f->rm_zero)
		str--;
	if (*str == '.' && !f->hashtag)
		f->rm_zero--;
	len = (f->len + f->precision + f->width + (2 + f->e_len) * (f->p
			|| f->b_len == 16) + f->rm_zero + (f->precision > f->rm_zero
			|| f->hashtag || (neg & 2 && !f->c_prec)));
	len = (f->c_width - len) * (f->c_width - len > 0);
	if (!f->minus && len - (f->precision == 0) > 0)
	{
		if (!f->zero && pf_put_width(' ', len - (f->precision == 0), f) < 0)
			return (-1);
		if (f->zero == 2)
			add_zero(len - (f->precision == 0), first, f, neg);
		else
			f->width += (len - (f->precision == 0)) * (f->c_width > 0);
	}
	else if (len - (f->precision == 0) > 0)
		f->width += (len - (f->precision == 0)) * (f->c_width > 0);
	return (0);
}

void	pf_round_float(char *str, char *base, t_flags *f, int i)
{
	str += (*str == '.');
	if (*str > base[f->b_len / 2] || ((f->precision != 0
		|| f->b_len == 10) && *str == base[f->b_len / 2]))
	{
		while (*(--str) == base[f->b_len - 1])
			*str = '0';
		if (*str != '.')
		{
			if (*str == '9')
				*str += 40 - (i * 32);
			else
				*str += 1;
		}
		else
		{
			if (*(str - 1) == '9')
				*(str - 1) += 40 - (i * 32);
			else
				*(str - 1) += 1;
		}
	}
}
