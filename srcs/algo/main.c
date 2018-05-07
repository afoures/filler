/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:03:28 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 12:06:42 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_map		map;
	t_piece		piece;

	map = (t_map){NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0};
	piece = (t_piece){NULL, 0, 0, 0, 0, 0, 0};
	if (get_player(&map) | get_map_coord(&map) | get_map(&map))
		return (-1);
	while (1)
	{
		if (get_piece(&piece))
			return (-1);
		if (!map.end && algo(&map, &piece))
			break ;
		else if (map.end && secondary_algo(&map, &piece))
			break ;
		if (update_map(&map))
			return (-1);
	}
	return (0);
}
