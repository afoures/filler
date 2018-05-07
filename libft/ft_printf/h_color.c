/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:13:20 by afoures           #+#    #+#             */
/*   Updated: 2018/02/01 12:09:07 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

void	pf_init_color(char **c)
{
	int		i;

	i = 0;
	while (i < 26)
		c[i++] = NULL;
	c[1] = BLUE;
	c[2] = CYAN;
	c[3] = BLACK;
	c[6] = GREEN;
	c[13] = NO_C;
	c[14] = ORANGE;
	c[15] = PURPLE;
	c[17] = RED;
	c[22] = WHITE;
	c[24] = YELLOW;
}

int		pf_color(unsigned char **fmt, int fd)
{
	char	*c[26];
	char	*str;
	int		i;

	(*fmt)++;
	i = 7 - 3 * (**fmt == 'n');
	if (**fmt <= 'a' || **fmt >= 'z' || **fmt == 'e' || **fmt == 'f'
		|| (**fmt >= 'h' && **fmt <= 'm') || **fmt == 'q'
		|| (**fmt >= 's' && **fmt <= 'v') || **fmt == 'x')
	{
		pf_put_buf(fd, "{", 1, 0);
		(*fmt)--;
		return (1);
	}
	pf_init_color(c);
	str = c[(int)**fmt - 'a'];
	(*fmt)++;
	if (!str)
		return (0);
	pf_put_buf(fd, str, i, 1);
	return (0);
}
