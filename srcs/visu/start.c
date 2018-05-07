/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:21:21 by afoures           #+#    #+#             */
/*   Updated: 2018/05/05 22:08:26 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static const char	*g_start[4] = {
	"Welcome into Filler Visualisator",
	"made by afoures",
	"Press any KEY to start the game",
	"Press TAB for help",
};

static void	start_player(t_window *win, t_state *state, SDL_Surface *start
								, SDL_Surface *tmp)
{
	int			line_width;
	int			line_height;
	char		player[50];

	ft_bzero(player, 50);
	ft_sprintf(player, "P1 %s", state->p1);
	if (TTF_SizeText(win->ttf_winner, player, &line_width, &line_height))
		display_error("error: bad start surface");
	tmp = TTF_RenderUTF8_Blended(win->ttf_winner, player,
								argb_to_sdl((Uint32)P1_NIGHT));
	put_text(start, tmp, win->width / 4 - line_width / 2,
			win->height / 2 - line_height / 2);
	SDL_FreeSurface(tmp);
	ft_bzero(player, 50);
	ft_sprintf(player, "P2 %s", state->p2);
	if (TTF_SizeText(win->ttf_winner, player, &line_width, &line_height))
		display_error("error: bad start surface");
	tmp = TTF_RenderUTF8_Blended(win->ttf_winner, player,
								argb_to_sdl((Uint32)P2_NIGHT));
	put_text(start, tmp, 3 * win->width / 4 - line_width / 2,
			win->height / 2 - line_height / 2);
	SDL_FreeSurface(tmp);
}

static void	start_text(t_window *win, SDL_Surface *start
	, SDL_Surface *tmp)
{
	int			line_width;
	int			line_height;

	if (TTF_SizeText(win->ttf_winner, g_start[0], &line_width, &line_height))
		display_error("error: bad start surface");
	tmp = TTF_RenderUTF8_Blended(win->ttf_winner, g_start[0],
								(SDL_Color){255, 255, 255, 255});
	put_text(start, tmp, (win->width - line_width) / 2,
			(win->height - win->height / 2) / 2 - line_height - 3);
	SDL_FreeSurface(tmp);
	if (TTF_SizeText(win->ttf_help, g_start[1], &line_width, &line_height))
		display_error("error: bad start surface");
	tmp = TTF_RenderUTF8_Blended(win->ttf_help, g_start[1],
								(SDL_Color){255, 255, 255, 255});
	put_text(start, tmp, (win->width - line_width) / 2,
			(win->height - win->height / 2) / 2);
	SDL_FreeSurface(tmp);
	if (TTF_SizeText(win->ttf_winner, g_start[2], &line_width, &line_height))
		display_error("error: bad start surface");
	tmp = TTF_RenderUTF8_Blended(win->ttf_winner, g_start[2],
								(SDL_Color){255, 255, 255, 255});
	put_text(start, tmp, (win->width - line_width) / 2,
			(win->height + (win->height / 2)) / 2);
	SDL_FreeSurface(tmp);
}

static void	create_surface(t_window *win, t_state *state, SDL_Surface *start)
{
	int			line_width;
	int			line_height;
	SDL_Surface	*tmp;

	if (TTF_SizeText(win->ttf_winner, g_start[3], &line_width, &line_height))
		display_error("error: bad start surface");
	tmp = TTF_RenderUTF8_Blended(win->ttf_winner, g_start[3],
								(SDL_Color){255, 255, 255, 255});
	put_text(start, tmp, (win->width - line_width) / 2,
			(win->height + (win->height / 2)) / 2 + line_height + 3);
	SDL_FreeSurface(tmp);
	start_text(win, start, tmp);
	start_player(win, state, start, tmp);
	if (TTF_SizeText(win->ttf_winner, "VS", &line_width, &line_height))
		display_error("error: bad start surface");
	tmp = TTF_RenderUTF8_Blended(win->ttf_winner, "VS",
								(SDL_Color){255, 255, 255, 255});
	put_text(start, tmp, win->width / 2 - line_width / 2,
			win->height / 2 - line_height / 2);
	SDL_FreeSurface(tmp);
}

void		create_start_menu(t_window *win, t_state *state)
{
	SDL_Surface	*start;

	state->game_started = 0;
	start = SDL_CreateRGBSurface(0, win->width, win->height,
									32, 0xff, 0xff00, 0xff0000, 0xff000000);
	put_rect(start, (t_rect){0, 0, win->width, win->height}, 0x000000);
	create_surface(win, state, start);
	SDL_BlitSurface(start, NULL, win->surface, NULL);
	SDL_UpdateWindowSurface(win->window);
	SDL_FreeSurface(start);
}
