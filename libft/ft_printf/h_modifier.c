/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_modifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:42:39 by afoures           #+#    #+#             */
/*   Updated: 2018/01/14 21:32:08 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		pf_m_h(va_list ap, t_flags *f)
{
	(void)ap;
	if ((int)f->modifier > (int)h)
		return (0);
	if ((int)f->modifier == (int)h)
	{
		f->modifier = hh;
		return (0);
	}
	f->modifier = h;
	return (0);
}

int		pf_m_l(va_list ap, t_flags *f)
{
	(void)ap;
	if ((int)f->modifier > (int)ll)
		return (0);
	if ((int)f->modifier == (int)l)
	{
		f->modifier = ll;
		return (0);
	}
	f->modifier = l;
	return (0);
}

int		pf_m_j(va_list ap, t_flags *f)
{
	(void)ap;
	if ((int)f->modifier < (int)j)
		f->modifier = j;
	return (0);
}

int		pf_m_z(va_list ap, t_flags *f)
{
	(void)ap;
	f->modifier = z;
	return (0);
}

int		pf_m_q(va_list ap, t_flags *f)
{
	(void)ap;
	if ((int)f->modifier > (int)ll)
		return (0);
	f->modifier = ll;
	return (0);
}
