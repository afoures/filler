/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:34:57 by afoures           #+#    #+#             */
/*   Updated: 2018/02/15 16:19:53 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

char		*pf_create_base(int i)
{
	if (i)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

static void	int_integral(char *str, uintmax_t nbr, int *tmp, t_flags *f)
{
	int		i;

	i = 0;
	while (nbr || *tmp)
	{
		if ((i % 3) == 0 && i > 0 && f->apostrophe)
		{
			str[*tmp - 1] = f->apostrophe;
			i = 0;
		}
		else
		{
			str[*tmp - 1] = nbr % 10 + '0';
			nbr /= 10;
			i++;
		}
		(*tmp)--;
	}
}

int			pf_int_toa(intmax_t nb, t_flags *f)
{
	uintmax_t	nbr;
	int			tmp;
	char		*str;
	char		s;

	tmp = f->len;
	nbr = (nb < 0 ? -nb : nb);
	s = ' ' + 11 * f->plus;
	if (!(str = malloc(sizeof(*str) * tmp)))
		return (pf_put_error("malloc error\n", 13));
	int_integral(str, nbr, &tmp, f);
	if (nb < 0)
		*str = '-';
	else if (f->plus || f->space)
		*str = s;
	pf_put_buf(f->fd, str, f->len, 1);
	free(str);
	return (f->len);
}

static void	uint_integral(char *str, uintmax_t nb, char *base, t_flags *f)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = f->len;
	while (nb || tmp)
	{
		if ((i % 3) == 0 && i > 0 && f->apostrophe)
		{
			str[tmp - 1] = f->apostrophe;
			i = 0;
		}
		else
		{
			str[tmp - 1] = base[nb % f->b_len];
			nb /= f->b_len;
			i++;
		}
		tmp--;
	}
}

int			pf_uint_toa(uintmax_t nb, char *base, t_flags *f)
{
	char		*str;

	if (!(str = malloc(sizeof(*str) * f->len)))
		return (pf_put_error("malloc error\n", 13));
	uint_integral(str, nb, base, f);
	if (f->hashtag && (nb > 0 || f->p))
		pf_put_hashtag(str, f, base);
	pf_put_buf(f->fd, str, f->len, 1);
	free(str);
	return (f->len);
}
