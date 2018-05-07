/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 18:10:16 by marvin            #+#    #+#             */
/*   Updated: 2018/03/05 10:46:06 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		pf_float_toa(long double nb, t_flags *f)
{
	int				tmp;
	char			*str;

	tmp = f->len;
	if (!(str = malloc(sizeof(*str) * (tmp + f->precision + 2) + 1)))
		return (pf_put_error("malloc error\n", 13));
	pf_float_integral(str, (intmax_t)nb, &tmp, f);
	str[f->len] = '.';
	pf_decimal(str, nb, tmp, f);
	pf_round_float(str + f->len + f->precision + (f->precision > 0
				|| f->hashtag) + (f->precision == 0), "0123456789", f, 0);
	if (nb < 0 || f->plus || f->space)
		*str = '-' - 2 * (f->plus && nb >= 0) - 13 * (f->space && nb >= 0);
	pf_put_buf(f->fd, str, f->len + f->precision
			+ (f->precision > 0 || f->hashtag), 1);
	free(str);
	return (f->len + f->precision + 1);
}

int		pf_efloat_toa(long double nb, t_flags *f, int e, int i)
{
	int			tmp;
	char		*str;

	tmp = f->len;
	if (!(str = malloc(sizeof(*str) * (f->len + f->precision + 7) + 1)))
		return (pf_put_error("malloc error\n", 13));
	pf_float_integral(str, (intmax_t)nb, &tmp, f);
	str[f->len] = '.';
	pf_decimal(str, nb, tmp, f);
	pf_round_float(str + f->len + f->precision
				+ (f->precision > 0 || f->hashtag), "0123456789", f, 0);
	if (nb < 0 || f->plus || f->space)
		*str = '-' - 2 * (f->plus && nb >= 0) - 13 * (f->space && nb >= 0);
	pf_put_buf(f->fd, str, f->len + f->precision
			+ (f->precision > 0 || f->hashtag), 1);
	if (pf_put_exponent(e, 'e' - i * 32, f) < 0)
		return (-1);
	free(str);
	return (f->len + f->precision + 1);
}

int		pf_afloat_toa(long double nb, t_flags *f, int e, int i)
{
	int			tmp;
	char		*str;
	char		*base;

	base = pf_create_base(i);
	if (!(str = malloc(sizeof(*str) * (f->len + f->precision + f->width + 9))))
		return (pf_put_error("malloc error\n", 13));
	tmp = f->len;
	pf_float_integral(str, (intmax_t)nb, &tmp, f);
	str[f->len] = '.';
	str[(nb < 0 || f->plus || f->space)] = '0';
	str[(nb < 0 || f->plus || f->space) + 1] = 'x' - i * 32;
	pf_adecimal(str, nb, 0, f);
	tmp = f->len + f->precision;
	pf_round_float(str + tmp + (f->precision > 0 || f->hashtag), base, f, i);
	if (nb < 0 || f->plus || f->space)
		*str = '-' - 2 * (f->plus && nb >= 0) - 13 * (f->space && nb >= 0);
	if (!f->c_prec && pf_rm_zero(str + tmp, f, str, nb < 0 + 2 * nb == 0.) < 0)
		return (-1);
	pf_put_buf(f->fd, str, f->len + f->precision + (f->precision > f->rm_zero
			|| f->hashtag || (nb == 0. && !f->c_prec)) + f->rm_zero, 1);
	if (pf_put_a_exponent(e, 'p' - i * 32, f) < 0)
		return (-1);
	free(str);
	return (0);
}

int		pf_gf_float_toa(long double nb, t_flags *f)
{
	int				tmp;
	char			*str;

	tmp = f->len;
	if (!(str = malloc(sizeof(*str) * (tmp + f->precision + 2) + 1)))
		return (pf_put_error("malloc error\n", 13));
	pf_float_integral(str, (intmax_t)nb, &tmp, f);
	str[f->len] = '.';
	pf_decimal(str, nb, tmp, f);
	pf_round_float(str + f->len + f->precision + (f->precision > 0
				|| f->hashtag), "0123456789", f, 0);
	if (nb < 0 || f->plus || f->space)
		*str = '-' - 2 * (f->plus && nb >= 0) - 13 * (f->space && nb >= 0);
	if (!f->hashtag
		&& pf_rm_zero(str + f->len + f->precision, f, str, (nb < 0) + 2
		* (nb == 0.)) < 0)
		return (-1);
	pf_put_buf(f->fd, str, f->len + f->precision
	+ (f->precision > f->rm_zero || f->hashtag || nb == 0.) + f->rm_zero, 1);
	free(str);
	return (0);
}

int		pf_ge_float_toa(long double nb, t_flags *f, int e, int i)
{
	int			tmp;
	char		*str;

	tmp = f->len;
	if (!(str = malloc(sizeof(*str) * (f->len + f->precision + 7) + 1)))
		return (pf_put_error("malloc error\n", 13));
	pf_float_integral(str, (intmax_t)nb, &tmp, f);
	str[f->len] = '.';
	pf_decimal(str, nb, tmp, f);
	pf_round_float(str + f->len + f->precision
				+ (f->precision > 0 || f->hashtag), "0123456789", f, 0);
	if (nb < 0 || f->plus || f->space)
		*str = '-' - 2 * (f->plus && nb >= 0) - 13 * (f->space && nb >= 0);
	if (!f->hashtag
		&& pf_rm_zero(str + f->len + f->precision, f, str, (nb < 0) + 2
		* (nb == 0.)) < 0)
		return (-1);
	pf_put_buf(f->fd, str, f->len + f->precision
	+ (f->precision > f->rm_zero || f->hashtag || nb == 0.) + f->rm_zero, 1);
	if (pf_put_exponent(e, 'e' - i * 32, f) < 0)
		return (-1);
	free(str);
	return (f->len + f->precision + 1);
}
