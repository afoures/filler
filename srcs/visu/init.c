/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:21:21 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 15:40:27 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	init_window(t_window *win)
{
	if (!(win->window = SDL_CreateWindow("Filler Visualisator by afoures",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		win->width, win->height, SDL_WINDOW_SHOWN)))
		display_error("error: SDL CreateWindow");
	win->surface = SDL_GetWindowSurface(win->window);
	SDL_SetSurfaceAlphaMod(win->surface, 255);
	SDL_SetSurfaceBlendMode(win->surface, SDL_BLENDMODE_BLEND);
}

void	init_font(t_window *win)
{
	if (TTF_Init() < 0)
		display_error("error: SDL Init");
	win->ttf_help = NULL;
	win->ttf_winner = NULL;
	win->ttf_help = TTF_OpenFont("resources/upheavtt.ttf", 20);
	win->ttf_winner = TTF_OpenFont("resources/upheavtt.ttf", 30);
	if (win->ttf_help == NULL || win->ttf_winner == NULL)
		display_error("error: loading font");
}

void	init_music(t_window *win)
{
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
		display_error("error: Music Init");
	win->tetris = NULL;
	win->darude = NULL;
	win->esaxguy = NULL;
	win->nggyu = NULL;
	win->tetris = Mix_LoadMUS("resources/tetris.ogg");
	win->darude = Mix_LoadMUS("resources/darude.ogg");
	win->esaxguy = Mix_LoadMUS("resources/esaxguy.ogg");
	win->nggyu = Mix_LoadMUS("resources/nggyu.ogg");
	if (win->tetris == NULL || win->darude == NULL
		|| win->esaxguy == NULL || win->nggyu == NULL)
		display_error("error: loading music");
}

void	init_sdl(t_window *win, t_state *state)
{
	(void)state;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		display_error("error: SDL Init");
	init_window(win);
	init_font(win);
	init_music(win);
	SDL_GL_SetSwapInterval(1);
	put_rect(win->surface, (t_rect){0, 0, win->width, win->height}, 0);
	SDL_UpdateWindowSurface(win->window);
}
