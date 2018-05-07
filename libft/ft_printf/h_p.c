/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_p.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:07:13 by afoures           #+#    #+#             */
/*   Updated: 2018/01/14 21:52:53 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int			pf_h_p(va_list ap, t_flags *f)
{
	f->modifier = l;
	f->hashtag = 1;
	f->p = 1;
	return (pf_h_x(ap, f));
}
