/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:41:48 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 15:40:27 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		main(void)
{
	t_window	win;
	t_state		state;
	t_turn		*first;
	t_turn		*current;
	int			i;

	current = NULL;
	first = NULL;
	state = (t_state){0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0};
	check_vm(&state, &win, &first, &current);
	i = -15;
	while (1)
	{
		get_event(&win, &state, first);
		if (!state.game_finished)
			current = get_turn(current, &state);
		if (state.game_started && i >= state.speed && !state.tab)
		{
			draw_next(&win, &state);
			i = 0;
		}
		i += !state.pause * state.game_started;
	}
	return (0);
}
