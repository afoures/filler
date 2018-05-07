/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:26:34 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 15:40:27 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	process_music(t_window *win, Mix_Music *music)
{
	if (win->event.key.keysym.sym == SDLK_F1
		|| win->event.key.keysym.sym == SDLK_F2)
	{
		if (Mix_PlayingMusic() == 1)
			Mix_HaltMusic();
		music = (win->event.key.keysym.sym == SDLK_F1) ? win->tetris :
					win->darude;
		Mix_PlayMusic(music, -1);
	}
	if (win->event.key.keysym.sym == SDLK_F3
		|| win->event.key.keysym.sym == SDLK_F4)
	{
		if (Mix_PlayingMusic() == 1)
			Mix_HaltMusic();
		music = (win->event.key.keysym.sym == SDLK_F3) ? win->esaxguy :
				win->nggyu;
		Mix_PlayMusic(music, -1);
	}
	if (win->event.key.keysym.sym == SDLK_p)
	{
		if (Mix_PausedMusic() == 1)
			Mix_ResumeMusic();
		else
			Mix_PauseMusic();
	}
}

void	process_theme(t_window *win, t_state *state)
{
	if (win->event.key.keysym.sym == SDLK_n)
	{
		state->k = 0. * (state->k > 0.5) + 1. * (state->k <= 0.5);
		draw_current(win, state);
	}
	if (win->event.key.keysym.sym == SDLK_KP_MINUS)
	{
		state->k -= 0.03;
		if (state->k < 0.)
			state->k = 0.;
		draw_current(win, state);
	}
	if (win->event.key.keysym.sym == SDLK_KP_PLUS)
	{
		state->k += 0.03;
		if (state->k > 1.)
			state->k = 1.;
		draw_current(win, state);
	}
}

void	process_game(t_window *win, t_state *state, t_turn *first)
{
	static int		speed = 0;

	if (win->event.key.keysym.sym == SDLK_SPACE)
		state->pause = (state->pause == 0);
	if (win->event.key.keysym.sym == SDLK_RETURN)
	{
		state->current = first;
		draw_current(win, state);
	}
	if (state->pause && win->event.key.keysym.sym == SDLK_RIGHT)
	{
		if (speed >= state->speed)
			draw_next(win, state);
		speed += 1 - (speed) * (speed >= state->speed);
	}
	if (state->pause && win->event.key.keysym.sym == SDLK_LEFT)
	{
		if (speed >= state->speed)
			draw_prev(win, state);
		speed += 1 - (speed) * (speed >= state->speed);
	}
	if (win->event.key.keysym.sym == SDLK_UP)
		state->speed -= 1 * (state->speed >= 2);
	if (win->event.key.keysym.sym == SDLK_DOWN)
		state->speed += 1 * (state->speed < 9);
}

void	process_keys(t_window *win, t_state *state, t_turn *first)
{
	Mix_Music *music;

	music = NULL;
	if (win->event.key.keysym.sym == SDLK_TAB)
	{
		if (!state->tab && (state->tab = 1))
			draw_help(win, state,
				(TTF_FontLineSkip(win->ttf_help) + 25) * 9 + 50);
	}
	process_game(win, state, first);
	process_theme(win, state);
	process_music(win, music);
}

void	get_event(t_window *win, t_state *state, t_turn *first)
{
	while (SDL_PollEvent(&win->event))
	{
		if (win->event.type == SDL_QUIT || (win->event.key.type == SDL_KEYDOWN
				&& win->event.key.keysym.sym == SDLK_ESCAPE))
			clean_quit(win);
		if (win->event.key.type == SDL_KEYDOWN)
		{
			if (!state->game_started)
			{
				if (win->event.key.keysym.sym == SDLK_TAB && !state->tab
					&& (state->tab = 1))
					draw_help(win, state,
						(TTF_FontLineSkip(win->ttf_help) + 25) * 9 + 50);
				else
					draw_current(win, state);
				state->game_started = 1;
				state->pause = 0;
			}
			else if (!state->tab)
				process_keys(win, state, first);
		}
		if (win->event.key.type == SDL_KEYUP
			&& win->event.key.keysym.sym == SDLK_TAB && !(state->tab = 0))
			draw_current(win, state);
	}
}
