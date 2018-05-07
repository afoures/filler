/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:04:07 by afoures           #+#    #+#             */
/*   Updated: 2018/03/04 19:38:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		ft_vprintf(const char *format, va_list ap)
{
	int				ret;
	int				i;

	ret = 0;
	if (pf_init_buf(NULL) < 0)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			if ((i = (parser((unsigned char **)&format, ap, &ret, 1))) < 0)
				return (pf_put_minus_one(1));
			ret += i;
		}
		else if (*format == '{')
			ret += pf_color((unsigned char **)&format, 1);
		else
			ret += pf_put_buf(1, (char *)format, 1, 0);
		if (*format)
			format++;
	}
	pf_write_buf(1, 0);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	int				ret;

	ret = 0;
	va_start(ap, format);
	ret = ft_vprintf(format, ap);
	va_end(ap);
	return (ret);
}
