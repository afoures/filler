/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_winner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:33:47 by afoures           #+#    #+#             */
/*   Updated: 2018/05/07 18:42:33 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	put_score(t_window *win, t_state *state, SDL_Surface *winner)
{
	SDL_Surface	*tmp;
	int			line_width;
	int			line_height;
	char		str[200];
	SDL_Color	color;

	ft_bzero(str, 200);
	if (state->score1 == state->score2)
		ft_sprintf(str, "Draw");
	else
		ft_sprintf(str, "P%d %s won",
		2 - 1 * (state->score1 > state->score2),
		(state->score1 > state->score2) ? state->p1 : state->p2);
	if (TTF_SizeText(win->ttf_winner, str, &line_width, &line_height))
		display_error("error: bad winner surface");
	if (state->score1 > state->score2)
		color = argb_to_sdl(get_color((t_color)P1_NIGHT, (t_color)P1_DAY,
					state->k));
	else
		color = argb_to_sdl(get_color((t_color)P2_NIGHT, (t_color)P2_DAY,
					state->k));
	tmp = TTF_RenderUTF8_Blended(win->ttf_winner, str, color);
	put_text(winner, tmp, (win->width - line_width) / 2,
			(win->height - line_height) / 2);
	SDL_FreeSurface(tmp);
}

void	put_winner(t_window *win, t_state *state)
{
	SDL_Surface	*tmp;
	SDL_Surface	*winner;
	int			line_width;
	int			line_height;
	char		str[200];

	winner = SDL_CreateRGBSurface(0, win->width, win->height,
									32, 0xff, 0xff00, 0xff0000, 0xff000000);
	put_rect(winner, (t_rect){0, 0, win->width, win->height}, 0xC0000000);
	put_score(win, state, winner);
	ft_bzero(str, 200);
	ft_sprintf(str, "%d vs %d", state->score1 + (state->score2 - state->score1)
		* (state->score2 > state->score1), state->score2 + (state->score1
		- state->score2) * (state->score2 > state->score1));
	if (TTF_SizeText(win->ttf_winner, str, &line_width, &line_height))
		display_error("error: bad winner surface");
	tmp = TTF_RenderUTF8_Blended(win->ttf_winner, str,
									(SDL_Color){255, 255, 255, 255});
	put_text(winner, tmp, (win->width - line_width) / 2,
			(win->height + line_height) / 2);
	SDL_BlitSurface(winner, NULL, win->surface, NULL);
	SDL_FreeSurface(tmp);
	SDL_FreeSurface(winner);
}
