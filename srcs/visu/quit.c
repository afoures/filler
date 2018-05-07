/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:21:21 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 15:40:27 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	clean_quit(t_window *win)
{
	SDL_FreeSurface(win->surface);
	SDL_DestroyWindow(win->window);
	Mix_FreeMusic(win->tetris);
	Mix_FreeMusic(win->darude);
	Mix_FreeMusic(win->esaxguy);
	Mix_FreeMusic(win->nggyu);
	TTF_CloseFont(win->ttf_help);
	TTF_CloseFont(win->ttf_winner);
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
	exit(0);
}

void	display_error(char *error)
{
	ft_dprintf(2, "%s\n", error);
	exit(-1);
}
