/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:21:21 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 15:40:27 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

Uint32		get_color(t_color c1, t_color c2, double k)
{
	int		i;
	t_color	c;

	i = -1;
	while (++i < 4)
		c.rgb[i] = c1.rgb[i] + (c2.rgb[i] - c1.rgb[i]) * k;
	return (c.color);
}

SDL_Color	argb_to_sdl(Uint32 color)
{
	t_color	c;

	c = (t_color)((int)color);
	return ((SDL_Color){c.rgb[2], c.rgb[1], c.rgb[0], c.rgb[3]});
}
