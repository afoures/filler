/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_k.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:00:41 by afoures           #+#    #+#             */
/*   Updated: 2018/04/03 11:48:17 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

static char	g_days[7][4] =
{
	"Sun",
	"Mon",
	"Tue",
	"Wed",
	"Thu",
	"Fri",
	"Sat"
};

static char	g_months[12][4] =
{
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dec"
};

void	h_k_bis(t_flags *f, struct tm *ti)
{
	char		str[10];

	str[0] = ti->tm_hour / 10 + '0';
	str[1] = ti->tm_hour % 10 + '0';
	str[2] = ':';
	str[3] = ti->tm_min / 10 + '0';
	str[4] = ti->tm_min % 10 + '0';
	str[5] = ':';
	str[6] = ti->tm_sec / 10 + '0';
	str[7] = ti->tm_sec % 10 + '0';
	str[8] = ' ';
	pf_put_buf(f->fd, str, 9, 1);
	str[0] = (ti->tm_year + 1900) / 1000 + '0';
	str[1] = ((ti->tm_year + 1900) / 100) % 10 + '0';
	str[2] = ((ti->tm_year + 1900) / 10) % 10 + '0';
	str[3] = (ti->tm_year + 1900) % 10 + '0';
	pf_put_buf(f->fd, str, 4, 1);
}

int		pf_h_k(va_list ap, t_flags *f)
{
	struct tm	*ti;
	char		str[10];

	ti = va_arg(ap, struct tm *);
	pf_put_buf(f->fd, g_days[ti->tm_wday], 3, 1);
	pf_put_buf(f->fd, " ", 1, 1);
	pf_put_buf(f->fd, g_months[ti->tm_mon], 3, 1);
	pf_put_buf(f->fd, "  ", 1 + (ti->tm_mday < 10), 1);
	str[0] = ti->tm_mday / 10 + '0';
	str[1] = ti->tm_mday % 10 + '0';
	str[2] = ' ';
	pf_put_buf(f->fd, str + (ti->tm_mday < 10), 2 + (ti->tm_mday >= 10), 1);
	h_k_bis(f, ti);
	f->ok = 1;
	return (24);
}
