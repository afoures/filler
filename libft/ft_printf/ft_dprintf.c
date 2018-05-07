/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 16:55:25 by afoures           #+#    #+#             */
/*   Updated: 2018/03/04 19:38:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		ft_vdprintf(int fd, const char *format, va_list ap)
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
			if ((i = (parser((unsigned char **)&format, ap, &ret, fd))) < 0)
				return (pf_put_minus_one(fd));
			ret += i;
		}
		else if (*format == '{')
			ret += pf_color((unsigned char **)&format, fd);
		else
			ret += pf_put_buf(fd, (char *)format, 1, 0);
		if (*format)
			format++;
	}
	return (ret - ((ret + 1) * (pf_write_buf(fd, 0) < 0)));
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list			ap;
	int				ret;

	ret = 0;
	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}
