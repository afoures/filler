/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:10:56 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 12:06:42 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_player(t_map *map)
{
	char	*str;
	int		i;

	i = 0;
	if (get_next_line(0, &str) <= 0)
		return (-1);
	while (str[i] && (ft_isalpha(str[i]) || ft_isspace(str[i])
			|| str[i] == '$'))
		i++;
	if (str[i])
	{
		map->player = (str[i] == '1') ? 'O' : 'X';
		map->opponent = (str[i] == '1') ? 'X' : 'O';
	}
	free(str);
	return (0);
}
