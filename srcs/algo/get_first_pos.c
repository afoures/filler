/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:32:28 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 12:06:42 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	add_player_pos(t_lstpos **first, int x, int y, char player)
{
	t_lstpos	*new;

	if (!(new = ft_memalloc(sizeof(t_lstpos) + 1)))
		return ;
	new->next = *first;
	new->x = x;
	new->y = y;
	new->player = player;
	*first = new;
}

void	get_player_first_pos(t_map *map, t_lstpos **first)
{
	int		y;
	int		x;

	y = -1;
	while (++y < map->h)
	{
		x = -1;
		while (++x < map->w)
		{
			if (map->current[y][x] != '.')
				add_player_pos(first, x, y, map->current[y][x]);
		}
	}
}
