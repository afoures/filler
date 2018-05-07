/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:18:21 by afoures           #+#    #+#             */
/*   Updated: 2018/01/14 21:19:05 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		pf_h_minus(va_list ap, t_flags *f)
{
	(void)ap;
	f->minus = 1;
	f->zero = 0;
	return (0);
}

int		pf_h_plus(va_list ap, t_flags *f)
{
	(void)ap;
	f->plus = 1;
	f->space = 0;
	return (0);
}

int		pf_h_hashtag(va_list ap, t_flags *f)
{
	(void)ap;
	f->hashtag = 1;
	return (0);
}

int		pf_h_space(va_list ap, t_flags *f)
{
	(void)ap;
	if (f->plus)
		return (0);
	f->space = 1;
	return (0);
}

int		pf_h_zero(va_list ap, t_flags *f)
{
	(void)ap;
	if (f->minus || f->precision != -1)
		return (0);
	f->zero = 1;
	return (0);
}
