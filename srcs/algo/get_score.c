/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:16:46 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 12:06:42 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			total_score(t_map *map)
{
	int		x;
	int		y;
	int		score;

	score = 0;
	y = -1;
	while (++y < map->h)
	{
		x = -1;
		while (++x < map->w)
		{
			if (map->tmp[y][x].who == 'O')
				score--;
			else if (map->tmp[y][x].who == 'X')
				score++;
		}
	}
	return (score);
}

void		reset_tmp(t_map *map)
{
	int			y;

	y = -1;
	while (++y < map->h)
	{
		ft_memcpy(map->tmp[y], map->score[y], sizeof(t_box) * (map->w + 1));
	}
}

void		put_piece_tmp(t_map *map, t_piece *p, t_point point)
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
				map->tmp[point.y + y][point.x + x].who = map->player;
				map->tmp[point.y + y][point.x + x].dist = 0;
				recalculate_up(map, (t_point){point.x + x
					, point.y + y - 1}, 1, map->player);
				recalculate_right(map, (t_point){point.x + x + 1
					, point.y + y}, 1, map->player);
				recalculate_down(map, (t_point){point.x + x
					, point.y + y + 1}, 1, map->player);
				recalculate_left(map, (t_point){point.x + x - 1
					, point.y + y}, 1, map->player);
			}
		}
	}
}

int			get_score(t_map *map, t_piece *piece, t_point point)
{
	int	score;

	put_piece_tmp(map, piece, point);
	score = total_score(map);
	reset_tmp(map);
	return (score);
}
