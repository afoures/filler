/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_w.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:40:46 by afoures           #+#    #+#             */
/*   Updated: 2018/02/22 14:07:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include <string.h>

char	rotx(char rot, t_flags *f)
{
	return ((rot - 32 + f->precision) % 95 + 32);
}

char	*cipher(char *to_cipher, char *str, t_flags *f, char *key)
{
	size_t	key_len;
	size_t	i;
	int		index;
	char	*tmp;

	if (!key)
		return (to_cipher);
	tmp = key;
	i = 0;
	index = -1;
	key_len = pf_strlen(key);
	while (++index < f->len)
	{
		*str = ((*to_cipher + rotx(*key, f) - 64) % 95 + 32)
				* (*to_cipher > 31) + *to_cipher * (*to_cipher <= 31);
		if (*to_cipher++ > 31)
		{
			i++;
			key++;
		}
		str++;
		if (i && i % key_len == 0)
			key = tmp;
	}
	return (str - f->len);
}

int		pf_h_w(va_list ap, t_flags *f)
{
	char	*str;
	char	*s;

	f->ok = 1;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	f->len = (int)pf_strlen(str);
	f->precision *= f->c_prec;
	if (!(s = malloc(sizeof(*s) * f->len + 1)))
		return (pf_put_error("malloc error\n", 13));
	cipher(str, s, f, KEY);
	pf_put_buf(f->fd, s, f->len, 1);
	free(s);
	return (f->len);
}

char	*decipher(char *to_cipher, char *str, t_flags *f, char *key)
{
	size_t	key_len;
	size_t	i;
	int		index;
	char	*tmp;

	if (!key)
		return (to_cipher);
	tmp = key;
	i = 0;
	index = -1;
	key_len = pf_strlen(key);
	while (++index < f->len)
	{
		*str = ((*to_cipher - rotx(*key, f) + 95) % 95 + 32)
				* (*to_cipher > 31) + *to_cipher * (*to_cipher <= 31);
		if (*to_cipher++ > 31)
		{
			i++;
			key++;
		}
		str++;
		if (i && i % key_len == 0)
			key = tmp;
	}
	return (to_cipher - f->len);
}

int		pf_h_ww(va_list ap, t_flags *f)
{
	char	*str;
	char	*s;

	f->ok = 1;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	f->len = (int)pf_strlen(str);
	f->precision *= f->c_prec;
	if (!(s = malloc(sizeof(*s) * f->len + 1)))
		return (pf_put_error("malloc error\n", 13));
	decipher(str, s, f, KEY);
	pf_put_buf(f->fd, s, f->len, 1);
	free(s);
	return (f->len);
}
