/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:21:21 by afoures           #+#    #+#             */
/*   Updated: 2018/05/05 22:08:34 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static const char	*g_help[9] = {
	"                       HELP MENU                       ",
	"RETURN : restart game",
	"SPACE : play/pause the game",
	"R/L ARROW : when game is paused, draw next/prev turn",
	"U/D ARROW : increase/decrease the speed of the game",
	"KEYPAD +/- : switch slowly to day/night mode",
	"N : switch instantly to day/night mode",
	"F1/../F4 : launch music",
	"P : if music is playing, pause/resume it"
};

static void		create_surface(t_window *win, int height)
{
	int			line_width;
	int			line_height;
	int			total_height;
	int			i;
	SDL_Surface	*tmp;

	i = -1;
	total_height = 0;
	while (++i < 9)
	{
		if (TTF_SizeText((i == 0) ? win->ttf_winner : win->ttf_help, g_help[i],
			&line_width, &line_height))
			display_error("error: bad help surface");
		tmp = TTF_RenderUTF8_Blended((i == 0) ? win->ttf_winner : win->ttf_help,
						g_help[i], (SDL_Color){255, 255, 255, 255});
		put_text(win->help, tmp, (win->width - line_width) / 2,
				(win->height - height) / 2 + total_height);
		SDL_FreeSurface(tmp);
		total_height += line_height + 25 + 50 * (i == 0);
	}
}

void			create_help_menu(t_window *win, t_state *state)
{
	int		help_height;

	(void)state;
	help_height = (TTF_FontLineSkip(win->ttf_help) + 25) * 9 + 50;
	win->help = SDL_CreateRGBSurface(0, win->width, win->height,
									32, 0xff, 0xff00, 0xff0000, 0xff000000);
	put_rect(win->help, (t_rect){0, 0, win->width, win->height}, 0xA0000000);
	create_surface(win, help_height);
	SDL_SetSurfaceBlendMode(win->surface, SDL_BLENDMODE_BLEND);
	SDL_SetSurfaceBlendMode(win->help, SDL_BLENDMODE_BLEND);
}

void			draw_help(t_window *win, t_state *state, int skipline)
{
	SDL_Surface	*tmp;
	int			line_width;
	int			line_height;
	char		player[50];

	SDL_BlitSurface(win->help, NULL, win->surface, NULL);
	ft_bzero(player, 50);
	ft_sprintf(player, "P1 %s", state->p1);
	if (TTF_SizeText(win->ttf_winner, player, &line_width, &line_height))
		display_error("error: bad help surface");
	tmp = TTF_RenderUTF8_Blended(win->ttf_winner, player,
	argb_to_sdl(get_color((t_color)P1_NIGHT, (t_color)P1_DAY, state->k)));
	put_text(win->surface, tmp, win->width / 2 - line_width - 15,
			(win->height - skipline) / 2 + line_height + 20);
	SDL_FreeSurface(tmp);
	ft_bzero(player, 50);
	ft_sprintf(player, "P2 %s", state->p2);
	if (TTF_SizeText(win->ttf_winner, player, &line_width, &line_height))
		display_error("error: bad help surface");
	tmp = TTF_RenderUTF8_Blended(win->ttf_winner, player,
	argb_to_sdl(get_color((t_color)P2_NIGHT, (t_color)P2_DAY, state->k)));
	put_text(win->surface, tmp, win->width / 2 + 15,
			(win->height - skipline) / 2 + line_height + 20);
	SDL_FreeSurface(tmp);
	SDL_UpdateWindowSurface(win->window);
}
