/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:17:15 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 12:06:42 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		recalculate_right(t_map *map, t_point p, int dist, char who)
{
	if (p.x < 0 || p.y < 0 || p.x >= map->w || p.y >= map->h)
		return ;
	if (map->tmp[p.y][p.x].dist == 0)
		return ;
	if (map->tmp[p.y][p.x].dist < dist)
		return ;
	if (map->tmp[p.y][p.x].dist == dist)
	{
		if (map->tmp[p.y][p.x].who != who)
			map->tmp[p.y][p.x].who = 'E';
		return ;
	}
	map->tmp[p.y][p.x].dist = dist;
	map->tmp[p.y][p.x].who = who;
	recalculate_right(map, (t_point){p.x + 1, p.y}, dist + 1, who);
	recalculate_right(map, (t_point){p.x, p.y + 1}, dist + 1, who);
	recalculate_right(map, (t_point){p.x, p.y - 1}, dist + 1, who);
}

void		recalculate_left(t_map *map, t_point p, int dist, char who)
{
	if (p.x < 0 || p.y < 0 || p.x >= map->w || p.y >= map->h)
		return ;
	if (map->tmp[p.y][p.x].dist == 0)
		return ;
	if (map->tmp[p.y][p.x].dist < dist)
		return ;
	if (map->tmp[p.y][p.x].dist == dist)
	{
		if (map->tmp[p.y][p.x].who != who)
			map->tmp[p.y][p.x].who = 'E';
		return ;
	}
	map->tmp[p.y][p.x].dist = dist;
	map->tmp[p.y][p.x].who = who;
	recalculate_left(map, (t_point){p.x - 1, p.y}, dist + 1, who);
	recalculate_left(map, (t_point){p.x, p.y + 1}, dist + 1, who);
	recalculate_left(map, (t_point){p.x, p.y - 1}, dist + 1, who);
}

void		recalculate_up(t_map *map, t_point p, int dist, char who)
{
	if (p.x < 0 || p.y < 0 || p.x >= map->w || p.y >= map->h)
		return ;
	if (map->tmp[p.y][p.x].dist == 0)
		return ;
	if (map->tmp[p.y][p.x].dist < dist)
		return ;
	if (map->tmp[p.y][p.x].dist == dist)
	{
		if (map->tmp[p.y][p.x].who != who)
			map->tmp[p.y][p.x].who = 'E';
		return ;
	}
	map->tmp[p.y][p.x].dist = dist;
	map->tmp[p.y][p.x].who = who;
	recalculate_up(map, (t_point){p.x, p.y - 1}, dist + 1, who);
	recalculate_up(map, (t_point){p.x + 1, p.y}, dist + 1, who);
	recalculate_up(map, (t_point){p.x - 1, p.y}, dist + 1, who);
}

void		recalculate_down(t_map *map, t_point p, int dist, char who)
{
	if (p.x < 0 || p.y < 0 || p.x >= map->w || p.y >= map->h)
		return ;
	if (map->tmp[p.y][p.x].dist == 0)
		return ;
	if (map->tmp[p.y][p.x].dist < dist)
		return ;
	if (map->tmp[p.y][p.x].dist == dist)
	{
		if (map->tmp[p.y][p.x].who != who)
			map->tmp[p.y][p.x].who = 'E';
		return ;
	}
	map->tmp[p.y][p.x].dist = dist;
	map->tmp[p.y][p.x].who = who;
	recalculate_down(map, (t_point){p.x, p.y + 1}, dist + 1, who);
	recalculate_down(map, (t_point){p.x + 1, p.y}, dist + 1, who);
	recalculate_down(map, (t_point){p.x - 1, p.y}, dist + 1, who);
}
