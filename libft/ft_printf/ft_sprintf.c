/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:59:01 by afoures           #+#    #+#             */
/*   Updated: 2018/03/04 22:11:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		ft_vsprintf(char *str, const char *format, va_list ap)
{
	int				ret;
	int				i;

	ret = 0;
	if (pf_init_buf(str) < 0)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			if ((i = (parser((unsigned char **)&format, ap, &ret, -1))) < 0)
				return (pf_puts_minus_one());
			ret += i;
		}
		else if (*format == '{')
			ret += pf_color((unsigned char **)&format, -1);
		else
			ret += pf_put_buf(-1, (char *)format, 1, 0);
		if (*format)
			format++;
	}
	pf_reset_buf_str(0);
	return (ret);
}

int		ft_sprintf(char *str, const char *format, ...)
{
	va_list			ap;
	int				ret;

	ret = 0;
	va_start(ap, format);
	ret = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (ret);
}
