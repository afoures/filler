/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:21:21 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 15:40:27 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		skip_piece(char *line)
{
	int		y;
	int		height;

	y = 0;
	height = ft_atoi(line + 5);
	free(line);
	while (y < height + 1)
	{
		if (get_next_line(0, &line) <= 0)
			display_error("error: bad Plateau");
		free(line);
		y++;
	}
	return (1);
}

int		add_turn(t_turn **current, t_state *state, char *line)
{
	t_turn	*new;
	int		i;

	if (!(new = ft_memalloc(sizeof(t_turn) + 1)))
		display_error("error: malloc");
	free(line);
	if (!(new->map = ft_memalloc(sizeof(char *) * (state->height + 1))))
		display_error("error: malloc");
	i = -1;
	if (get_next_line(0, &line) <= 0)
		display_error("error: bad turn");
	free(line);
	while (++i < state->height)
		if (get_next_line(0, &(new->map[i])) <= 0)
			display_error("error: bad turn");
	new->map[i] = NULL;
	new->next = NULL;
	new->prev = NULL;
	if (*current)
	{
		new->prev = *current;
		(*current)->next = new;
	}
	*current = new;
	return (1);
}

t_turn	*get_turn(t_turn *current, t_state *state)
{
	char	*line;

	while (1)
	{
		if (get_next_line(0, &line) <= 0)
			display_error("error: bad turn");
		if (ft_strstr(line, "Piece ") && skip_piece(line))
			continue ;
		if (ft_strstr(line, "== "))
		{
			state->score1 = ft_atoi(line + 9);
			free(line);
			if (get_next_line(0, &line) <= 0)
				display_error("error: bad turn");
			state->score2 = ft_atoi(line + 9);
			free(line);
			state->game_finished = 1;
			break ;
		}
		if (ft_strstr(line, "Plateau ") && add_turn(&current, state, line))
			break ;
		display_error("error: bad turn");
	}
	return (current);
}
