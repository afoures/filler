/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:12:20 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 17:24:34 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_piece(t_map *map, t_piece *p, t_point point)
{
	int		yp;
	int		xp;
	int		skip;

	skip = 0;
	yp = -1;
	while (++yp < p->h)
	{
		xp = -1;
		while (++xp < p->w)
		{
			if (p->piece[yp][xp] == '*')
			{
				if (xp + point.x < 0 || yp + point.y < 0
				|| xp + point.x >= map->w || yp + point.y >= map->h
				|| map->current[point.y + yp][point.x + xp] == map->opponent)
					return (0);
				skip += (map->current[point.y + yp]
						[point.x + xp] == map->player);
			}
		}
	}
	return (skip == 1);
}

int			algo(t_map *map, t_piece *piece)
{
	t_point		point;
	t_point		coord;
	t_point		score;

	point.y = -piece->h;
	coord = (t_point){0, 0};
	score = (t_point){(map->player == 'O') * (INT_MAX - INT_MIN) + INT_MIN, 0};
	while (++point.y < map->h)
	{
		point.x = -piece->w;
		while (++point.x < map->w)
			if (check_piece(map, piece, point))
			{
				score.y = get_score(map, piece, point);
				if ((score.y <= score.x && (map->player == 'O'))
					|| (score.y >= score.x && (map->player == 'X')))
				{
					score.x = score.y;
					coord = point;
				}
			}
	}
	ft_printf("%d %d\n", coord.y, coord.x);
	return (score.x == INT_MIN || score.x == INT_MAX);
}

int			secondary_algo(t_map *map, t_piece *piece)
{
	t_point		point;

	point.y = -piece->h;
	while (++point.y < map->h)
	{
		point.x = -piece->w;
		while (++point.x < map->w)
		{
			if (check_piece(map, piece, point))
			{
				ft_printf("%d %d\n", point.y, point.x);
				return (0);
			}
		}
	}
	return (write(1, "0 0\n", 4));
}
