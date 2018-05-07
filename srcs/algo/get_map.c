/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:19:02 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 12:06:42 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_map(t_map *map)
{
	int	y;

	if (!(map->current = (ft_memalloc(sizeof(char *) * (map->h + 1)))))
		return (-1);
	if (!(map->last = (ft_memalloc(sizeof(char *) * (map->h + 1)))))
		return (-1);
	if (!(map->score = (ft_memalloc(sizeof(t_box *) * (map->h + 1)))))
		return (-1);
	if (!(map->tmp = (ft_memalloc(sizeof(t_box *) * (map->h + 1)))))
		return (-1);
	y = -1;
	while (++y < map->h)
	{
		if (!(map->current[y] = (ft_memalloc(sizeof(char) * (map->w + 1)))))
			return (-1);
		if (!(map->last[y] = (ft_memalloc(sizeof(char) * (map->w + 1)))))
			return (-1);
		if (!(map->score[y] = (ft_memalloc(sizeof(t_box) * (map->w + 1)))))
			return (-1);
		if (!(map->tmp[y] = (ft_memalloc(sizeof(t_box) * (map->w + 1)))))
			return (-1);
	}
	return (0);
}

int		get_map_coord(t_map *map)
{
	char	*str;

	str = NULL;
	if (get_next_line(0, &str) <= 0)
		return (-1);
	if (!map->h || !map->w)
	{
		map->h = ft_atoi(str + 8);
		map->w = ft_atoi(str + 8 + ft_intlen(map->h));
	}
	if (!map->h | !map->w | (!map->current && init_map(map)))
		return (-1);
	free(str);
	return (0);
}

void	get_minimal_dist(t_map *map, t_lstpos *first, int x, int y)
{
	t_lstpos	*tmp;
	int			dist;

	tmp = first;
	while (tmp != NULL && map->current[y][x] == '.')
	{
		dist = ft_abs(x - tmp->x) + ft_abs(y - tmp->y);
		if (dist < map->score[y][x].dist)
		{
			map->score[y][x].dist = dist;
			map->score[y][x].who = tmp->player;
		}
		else if (dist == map->score[y][x].dist
					&& map->score[y][x].who != tmp->player)
			map->score[y][x].who = 'E';
		tmp = tmp->next;
		if (y == map->h - 1 && x == map->w - 1)
		{
			free(first);
			first = tmp;
		}
	}
}

void	calculate_dist(t_map *map)
{
	t_lstpos	*first;
	int			y;
	int			x;

	first = NULL;
	get_player_first_pos(map, &first);
	if (first == NULL)
		return ;
	y = -1;
	while (++y < map->h)
	{
		x = -1;
		while (++x < map->w)
		{
			map->score[y][x].dist = INT_MAX * (map->current[y][x] == '.');
			map->score[y][x].who = map->current[y][x]
									* (map->current[y][x] != '.');
			get_minimal_dist(map, first, x, y);
		}
		ft_memcpy(map->tmp[y], map->score[y], sizeof(t_box) * (map->w + 1));
	}
}

int		get_map(t_map *map)
{
	char		*str;
	t_point		point;

	str = NULL;
	if (get_next_line(0, &str) <= 0)
		return (-1);
	free(str);
	point.y = -1;
	while (++point.y < map->h)
	{
		if (get_next_line(0, &str) <= 0)
			return (-1);
		ft_memcpy(map->current[point.y], str + 4, sizeof(char) * map->w);
		ft_memcpy(map->last[point.y], str + 4, sizeof(char) * map->w);
		free(str);
	}
	calculate_dist(map);
	return (0);
}
