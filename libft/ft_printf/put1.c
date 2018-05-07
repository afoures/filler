/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 18:06:45 by marvin            #+#    #+#             */
/*   Updated: 2018/03/04 22:11:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		pf_put_error(char *error, int len)
{
	write(2, error, len);
	return (-1);
}

int		pf_put_minus_one(int fd)
{
	pf_write_buf(fd, 1);
	return (-1);
}

int		pf_puts_minus_one(void)
{
	pf_reset_buf_str(1);
	return (-1);
}

int		pf_put_exponent(int e, char c, t_flags *f)
{
	char	*str;

	if (!(str = malloc(sizeof(*str) * (4 + (e >= 100 || e <= -100)) + 1)))
		return (pf_put_error("malloc error\n", 13));
	str[0] = c;
	str[1] = '+' + (e < 0) * 2;
	e *= (e < 0) * -2 + 1;
	if (e >= 100 || e <= -100)
	{
		str[2] = (e / 100) % 10 + '0';
		str[3] = (e / 10) % 10 + '0';
		str[4] = e % 10 + '0';
	}
	else
	{
		str[2] = (e / 10) % 10 + '0';
		str[3] = e % 10 + '0';
	}
	pf_put_buf(f->fd, str, 4 + (e >= 100 || e <= -100), 1);
	free(str);
	return (0);
}

int		pf_put_a_exponent(int e, char c, t_flags *f)
{
	char	*str;
	char	*base;
	int		len;
	int		i;

	base = "0123456789";
	if (!(str = malloc(sizeof(*str) * (7 + (e >= 255 || e <= -255)) + 1)))
		return (pf_put_error("malloc error\n", 13));
	str[0] = c;
	str[1] = '+' + (e < 0) * 2;
	e *= (e < 0) * -2 + 1;
	len = 0;
	i = e + (e == 0) * 1;
	while (i && ++len)
		i /= 10;
	i = len;
	while (e || i)
	{
		str[i + 1] = base[e % 10];
		e /= 10;
		i--;
	}
	pf_put_buf(f->fd, str, 2 + len, 1);
	free(str);
	return (0);
}
