/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:13:33 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 15:40:27 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	draw_last(t_window *win, t_state *state)
{
	t_point	coord;

	coord.y = 0;
	put_rect(win->surface, (t_rect){0, 0, win->width, win->height}, NIGHT);
	while (coord.y < state->height)
	{
		coord.x = 0;
		while (coord.x < state->width)
		{
			if (state->current->map[coord.y][coord.x + 4] != '.')
				draw_lst_piece(win, state, coord,
							state->current->map[coord.y][coord.x + 4]);
			coord.x++;
		}
		coord.y++;
	}
	put_winner(win, state);
	SDL_UpdateWindowSurface(win->window);
}

void	draw_next(t_window *win, t_state *state)
{
	t_point	coord;

	coord.y = 0;
	if (state->current->next != NULL)
		state->current = state->current->next;
	else
	{
		draw_last(win, state);
		return ;
	}
	put_rect(win->surface, (t_rect){0, 0, win->width, win->height}, NIGHT);
	while (coord.y < state->height)
	{
		coord.x = 0;
		while (coord.x < state->width)
		{
			if (state->current->map[coord.y][coord.x + 4] != '.')
				draw_piece(win, state, coord,
							state->current->map[coord.y][coord.x + 4]);
			coord.x++;
		}
		coord.y++;
	}
	SDL_UpdateWindowSurface(win->window);
}

void	draw_current(t_window *win, t_state *state)
{
	t_point	coord;

	coord.y = 0;
	put_rect(win->surface, (t_rect){0, 0, win->width, win->height}, NIGHT);
	if (state->current->next == NULL)
	{
		draw_last(win, state);
		return ;
	}
	while (coord.y < state->height)
	{
		coord.x = 0;
		while (coord.x < state->width)
		{
			if (state->current->map[coord.y][coord.x + 4] != '.')
				draw_piece(win, state, coord,
							state->current->map[coord.y][coord.x + 4]);
			coord.x++;
		}
		coord.y++;
	}
	SDL_UpdateWindowSurface(win->window);
}

void	draw_prev(t_window *win, t_state *state)
{
	t_point	coord;

	coord.y = 0;
	if (state->current->prev != NULL)
		state->current = state->current->prev;
	else
		return ;
	put_rect(win->surface, (t_rect){0, 0, win->width, win->height}, NIGHT);
	while (coord.y < state->height)
	{
		coord.x = 0;
		while (coord.x < state->width)
		{
			if (state->current->map[coord.y][coord.x + 4] != '.')
				draw_piece(win, state, coord,
							state->current->map[coord.y][coord.x + 4]);
			coord.x++;
		}
		coord.y++;
	}
	SDL_UpdateWindowSurface(win->window);
}
