/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:30:21 by afoures           #+#    #+#             */
/*   Updated: 2018/03/04 22:13:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

static unsigned char	*g_buf = NULL;
static int				g_ibuf = 0;
static int				g_ierror = 0;

void	pf_cpy_to_buf(unsigned char *buffer, int *index, void *to_put, int len)
{
	unsigned char		*tmp1;
	unsigned long int	*tmp2;
	unsigned long int	*tmp3;
	int					i;

	tmp1 = (unsigned char *)to_put;
	tmp2 = (unsigned long int *)(buffer + *index);
	tmp3 = (unsigned long int *)to_put;
	i = 0;
	while (len > 8)
	{
		tmp2[i] = tmp3[i];
		i++;
		len -= 8;
		*index += 8;
	}
	i *= 8;
	while (len > 0)
	{
		buffer[*index] = tmp1[i];
		i++;
		len -= 1;
		*index += 1;
	}
}

int		pf_reset_buf_str(int error)
{
	if (error)
		g_buf[g_ierror] = '\0';
	g_buf = NULL;
	g_ibuf = 0;
	g_ierror = 0;
	return (0);
}

int		pf_init_buf(char *to_put)
{
	if (to_put)
	{
		if (g_buf)
			free(g_buf);
		g_buf = (unsigned char *)to_put;
	}
	else if (!g_buf)
		if (!(g_buf = malloc(sizeof(char) * (BUFF_SIZE_PF + 1))))
			return (pf_put_error("malloc buffer error\n", 20));
	return (0);
}

int		pf_write_buf(int fd, int error)
{
	int		len;

	if (error)
	{
		len = write(fd, g_buf, g_ierror);
		g_ibuf = 0;
		g_ierror = 0;
		return (len);
	}
	len = write(fd, g_buf, g_ibuf);
	g_ibuf = 0;
	g_ierror = 0;
	return (len);
}

int		pf_put_buf(int fd, void *to_put, int len, int error)
{
	if (fd >= 0 && g_ibuf + len > BUFF_SIZE_PF)
	{
		write(fd, g_buf, g_ibuf);
		g_ibuf = 0;
		g_ierror = 0;
	}
	if (fd >= 0 && len > BUFF_SIZE_PF)
	{
		write(fd, to_put, len);
		return (len);
	}
	pf_cpy_to_buf(g_buf, &g_ibuf, to_put, len);
	if (error)
		g_ierror = g_ibuf;
	return (len);
}
