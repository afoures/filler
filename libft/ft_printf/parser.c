/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:30:23 by afoures           #+#    #+#             */
/*   Updated: 2018/02/04 18:04:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int		parser(unsigned char **fmt, va_list ap, int *ret, int fd)
{
	t_flags			f;
	int				i;
	static int		(*fct[256])() = {NULL};

	f = (t_flags){0, 0, 0, 0, 0, 0, -1, 0, -1, 0, none, 0, 1, 10, 1, 0, 0, fd};
	(*fmt)++;
	i = 0;
	if (!fct[0])
		pf_init_table(fct);
	while (*fmt && (i = fct[(int)**fmt](ap, &f, fmt, ret)) >= 0 && f.ok == 0)
		(*fmt)++;
	return (i);
}
