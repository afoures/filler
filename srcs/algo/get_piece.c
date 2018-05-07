/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:09:22 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 12:06:42 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_real_p_coord(t_piece *p)
{
	int		y;
	int		x;

	y = -1;
	while (++y < p->h)
	{
		x = -1;
		while (++x < p->w)
		{
			if (p->piece[y][x] == '*')
			{
				p->endw = p->endw < x ? x : p->endw;
				p->endh = y;
				p->startw = p->startw > x ? x : p->startw;
				if (p->starth == -1 && p->startw > INT_MIN)
					p->starth = y;
			}
		}
	}
}

int		get_p_coord(t_piece *p)
{
	char	*str;

	if (get_next_line(0, &str) <= 0)
		return (-1);
	p->h = ft_atoi(str + 6);
	p->w = ft_atoi(str + 6 + ft_intlen(p->h));
	free(str);
	return (0);
}

void	free_piece(t_piece *p)
{
	int		i;

	i = 0;
	while (i < p->h)
	{
		free(p->piece[i]);
		i++;
	}
	free(p->piece);
	p->piece = NULL;
}

int		get_piece(t_piece *piece)
{
	char		*str;
	int			y;

	y = -1;
	str = NULL;
	if (piece->piece != NULL)
		free_piece(piece);
	if (get_p_coord(piece))
		return (-1);
	if (!(piece->piece = (ft_memalloc(sizeof(char *) * (piece->h + 1)))))
		return (-1);
	while (++y < piece->h)
	{
		if (get_next_line(0, &(piece->piece[y])) <= 0)
			return (-1);
		free(str);
	}
	piece->piece[y] = NULL;
	return (0);
}
