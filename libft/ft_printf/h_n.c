/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_n.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:22:20 by afoures           #+#    #+#             */
/*   Updated: 2018/01/29 12:17:52 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

void	pf_init_arg_n(intmax_t *(*pf_arg_n[8])(va_list ap))
{
	pf_arg_n[0] = pf_arg_n_none;
	pf_arg_n[1] = pf_arg_n_hh;
	pf_arg_n[2] = pf_arg_n_h;
	pf_arg_n[3] = pf_arg_n_ll;
	pf_arg_n[4] = pf_arg_n_l;
	pf_arg_n[5] = pf_arg_n_j;
	pf_arg_n[6] = pf_arg_n_z;
	pf_arg_n[7] = pf_arg_n_none;
}

int		pf_h_n(va_list ap, t_flags *f, unsigned char **fmt, int *ret)
{
	intmax_t	*dest;
	intmax_t	*(*pf_arg_n[8])(va_list);

	(void)fmt;
	pf_init_arg_n(pf_arg_n);
	dest = pf_arg_n[(int)f->modifier](ap);
	*dest = *ret;
	f->ok = 1;
	return (0);
}
