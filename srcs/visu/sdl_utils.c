/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:23:23 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 15:40:27 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	put_text(SDL_Surface *surface, SDL_Surface *text, int x, int y)
{
	SDL_BlitSurface(text, NULL, surface, &((SDL_Rect){x, y, 0, 0}));
}

void	put_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	((Uint32 *)surface->pixels)[y * surface->w + x] = pixel;
}

void	put_rect(SDL_Surface *surface, t_rect rectangle, Uint32 pixel)
{
	int		x;
	int		y;

	y = 0;
	while (y < rectangle.heigth)
	{
		x = 0;
		while (x < rectangle.width)
		{
			put_pixel(surface, rectangle.x + x, rectangle.y + y, pixel);
			x++;
		}
		y++;
	}
}

void	put_line(SDL_Surface *surface, t_point start, t_point end, Uint32 pixel)
{
	t_point		d;
	t_point		s;
	int			err1;
	int			err2;

	d.x = ft_abs(start.x - end.x);
	d.y = ft_abs(start.y - end.y);
	s.x = -1 + 2 * (start.x < end.x);
	s.y = -1 + 2 * (start.y < end.y);
	err1 = ((d.x > d.y) * d.x + (d.x <= d.y) * -d.y) / 2;
	while (1)
	{
		put_pixel(surface, start.x, start.y, pixel);
		if (start.x == end.x && start.y == end.y)
			break ;
		err2 = err1;
		err1 -= d.y * (err2 > -d.x);
		start.x += s.x * (err2 > -d.x);
		err1 += d.x * (err2 < d.y);
		start.y += s.y * (err2 < d.y);
	}
}
