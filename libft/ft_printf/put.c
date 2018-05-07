/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:51:18 by afoures           #+#    #+#             */
/*   Updated: 2018/02/15 20:59:47 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		pf_put_hashtag(char *str, t_flags *f, char *base)
{
	if ((f->b_len % 8) == 0 || f->p == 1)
		str[0] = '0';
	if ((f->b_len % 16) == 0 || f->p == 1)
		str[1] = base[15] + 18;
	return (0);
}

int		pf_put_width(char c, int len, t_flags *f)
{
	unsigned long int	*str;
	int					tmp;

	if (!(str = malloc(sizeof(*str) * len / 8 + 1)))
		return (pf_put_error("malloc error\n", 13));
	tmp = len / 8 + 1;
	while (tmp)
	{
		str[tmp - 1] = c << 8 | c;
		str[tmp - 1] = str[tmp - 1] << 16 | str[tmp - 1];
		str[tmp - 1] = str[tmp - 1] << 32 | str[tmp - 1];
		tmp--;
	}
	pf_put_buf(f->fd, (char *)str, len, f->minus);
	free(str);
	return (0);
}

int		pf_put_wstr(wchar_t *str, t_flags *f)
{
	int i;
	int	tmp;

	i = 0;
	tmp = f->len;
	while (tmp)
	{
		if (str[i] < 0 || str[i] > 0x10ffff || (str[i] >= 0xd800
			&& str[i] <= 0xdfff) || (MB_CUR_MAX == 1 && str[i] > 255))
			return (-1);
		pf_put_wchar_t(str[i], f, (tmp == 1));
		tmp--;
		i++;
	}
	return (f->len);
}

int		pf_put_wchar_t(wchar_t c, t_flags *f, int i)
{
	unsigned int	byte;

	if (!(c >> (7 + (MB_CUR_MAX == 1))))
		return (pf_put_buf(f->fd, &c, 1, i));
	else if (!(c >> 11))
	{
		byte = (((c & 0x3f) << 8) | (c >> 6)) | 0x80c0;
		return (pf_put_buf(f->fd, &byte, 2, i));
	}
	else if (!(c >> 16))
	{
		byte = (((c & 0x3f) << 16) | (((c >> 6) & 0x3f) << 8)
				| (c >> 12)) | 0x8080e0;
		return (pf_put_buf(f->fd, &byte, 3, i));
	}
	else if (!(c >> 21))
	{
		byte = (((((c & 0x3f) << 24) | (((c >> 6) & 0x3f) << 16))
				| (((c >> 12) & 0x3f) << 8)) | (c >> 18)) | 0x808080f0;
		return (pf_put_buf(f->fd, &byte, 4, i));
	}
	return (0);
}
