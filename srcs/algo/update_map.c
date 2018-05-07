/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:15:15 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 12:06:42 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	update_tmp(t_map *map)
{
	int			y;

	y = -1;
	while (++y < map->h)
	{
		ft_memcpy(map->score[y], map->tmp[y],
					sizeof(t_box) * (map->w + 1));
		ft_memcpy(map->last[y], map->current[y],
					sizeof(char) * (map->w + 1));
	}
}

void	update_dist(t_map *map)
{
	int			y;
	int			x;

	y = -1;
	map->end = 1;
	while (++y < map->h)
	{
		x = -1;
		while (++x < map->w)
			if (map->current[y][x] != map->last[y][x])
			{
				if (map->current[y][x] == map->opponent)
					map->end = 0;
				map->tmp[y][x].dist = 0;
				map->tmp[y][x].who = map->current[y][x];
				recalculate_up(map, (t_point){x, y - 1}, 1, map->current[y][x]);
				recalculate_right(map, (t_point){x + 1, y}, 1,
									map->current[y][x]);
				recalculate_down(map, (t_point){x, y + 1}, 1,
									map->current[y][x]);
				recalculate_left(map, (t_point){x - 1, y}, 1,
									map->current[y][x]);
			}
	}
	update_tmp(map);
}

int		update_map(t_map *map)
{
	char		*str;
	t_point		point;

	str = NULL;
	if (get_next_line(0, &str) <= 0)
		return (-1);
	free(str);
	if (get_next_line(0, &str) <= 0)
		return (-1);
	free(str);
	point.y = -1;
	while (++point.y < map->h)
	{
		if (get_next_line(0, &str) <= 0)
			return (-1);
		ft_memcpy(map->current[point.y], str + 4, sizeof(char) * map->w);
		free(str);
	}
	if (!map->end)
		update_dist(map);
	return (0);
}
