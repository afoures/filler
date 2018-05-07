/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:29:58 by afoures           #+#    #+#             */
/*   Updated: 2018/02/22 14:05:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		pf_get_wclen(wchar_t c, t_flags *f)
{
	f->len = (!(c >> (7 + (MB_CUR_MAX == 1))));
	f->len += (2 * (!(c >> 11)) * (f->len == 0));
	f->len += (3 * (!(c >> 16)) * (f->len == 0));
	f->len += (4 * (!(c >> 21)) * (f->len == 0));
	return (f->len);
}

int		pf_get_strlen(char *str, t_flags *f)
{
	if (f->precision != 0)
		f->len = (int)pf_strlen(str);
	else
		f->len = 0;
	if (f->len && f->precision != -1 && f->precision < f->len)
		f->len = f->precision;
	return (f->len);
}

int		pf_get_wstrlen(wchar_t *str, t_flags *f)
{
	if (f->precision != 0)
		f->len = pf_wchar_strlen(str, f);
	else
		f->len = 0;
	return (f->len);
}

size_t	pf_strlen(char *str)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i])
		i++;
	return (i);
}

size_t	pf_wchar_strlen(wchar_t *str, t_flags *f)
{
	size_t i;
	size_t len;
	size_t tmp;

	i = -1;
	len = 0;
	if (f->c_prec)
	{
		while (str[++i])
		{
			tmp = pf_get_wclen(str[i], f);
			if (f->precision < (int)(len + tmp))
				break ;
			len += tmp;
		}
		f->precision = len;
	}
	else
	{
		f->precision = 0;
		while (str[++i])
			f->precision += pf_get_wclen(str[i], f);
	}
	return (i);
}
