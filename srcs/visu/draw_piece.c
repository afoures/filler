/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:03:18 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 15:40:27 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	draw_piece(t_window *win, t_state *state, t_point coord, int who)
{
	Uint32		color;

	color = 0;
	if (who == 88)
		color = get_color((t_color)P2_NIGHT, (t_color)P2_DAY, state->k);
	else if (who == 79)
		color = get_color((t_color)P1_NIGHT, (t_color)P1_DAY, state->k);
	else if (who == 120)
		color = get_color((t_color)P2_LST_NIGHT, (t_color)P2_LST_DAY, state->k);
	else if (who == 111)
		color = get_color((t_color)P1_LST_NIGHT, (t_color)P1_LST_DAY, state->k);
	put_rect(win->surface,
	(t_rect){
		(coord.x) * (state->square_size + 1) + 1,
		(coord.y) * (state->square_size + 1) + 1,
		state->square_size,
		state->square_size
	},
	color);
}

void	draw_lst_piece(t_window *win, t_state *state, t_point coord, int who)
{
	Uint32		color;

	color = 0;
	if (who == 88 || who == 120)
		color = get_color((t_color)P2_NIGHT, (t_color)P2_DAY, state->k);
	else if (who == 79 || who == 111)
		color = get_color((t_color)P1_NIGHT, (t_color)P1_DAY, state->k);
	put_rect(win->surface,
	(t_rect){
		(coord.x) * (state->square_size + 1) + 1,
		(coord.y) * (state->square_size + 1) + 1,
		state->square_size,
		state->square_size
	},
	color);
}
