/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vm_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:21:21 by afoures           #+#    #+#             */
/*   Updated: 2018/05/05 21:41:54 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static const char	g_header[5][49] = {
	"# -------------- VM  version 1.1 ------------- #",
	"#                                              #",
	"# 42 / filler VM Developped by: Hcao - Abanlin #",
	"#                                              #",
	"# -------------------------------------------- #"
};

void	check_header(void)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (i < 5)
	{
		if (get_next_line(0, &line) <= 0)
			display_error("error: vm header");
		if (ft_strcmp(line, g_header[i]))
			display_error("error: vm header");
		free(line);
		i++;
	}
}

void	get_player(t_state *state)
{
	int		i;
	int		k;
	char	*line;
	char	*tmp;

	i = -1;
	line = NULL;
	while (++i < 2)
	{
		if (get_next_line(0, &line) <= 0 || *line != 'l')
			display_error("error: bad player");
		tmp = ft_strstr(line, "players/");
		k = 0;
		while (tmp[8 + k] && tmp[8 + k] != '.')
			k++;
		if (i == 0)
			state->p1 = ft_strsub(tmp, 8, k);
		else
			state->p2 = ft_strsub(tmp, 8, k);
		free(line);
		if (get_next_line(0, &line) <= 0)
			display_error("error: bad player");
		free(line);
	}
}

void	get_size(t_state *state, t_window *win)
{
	int		i;
	char	*line;

	if (get_next_line(0, &line) <= 0 && !ft_strstr(line, "Plateau "))
		display_error("error: bad Plateau");
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	state->height = ft_atoi(line + i);
	state->width = ft_atoi(line + i + ft_intlen(state->height) + 1);
	free(line);
	if (state->height <= 0 || state->width <= 0)
		display_error("error: bad Plateau");
	win->width = 0;
	win->height = 0;
	state->square_size = 9;
	while (win->width < 500 || win->height < 500 || win->width > 1400
		|| win->height > 1400)
	{
		state->square_size += (win->width < 500 || win->height < 500)
				- (win->width > 1400 || win->height > 1400);
		win->width = state->width * (state->square_size + 1) + 1;
		win->height = state->height * (state->square_size + 1) + 1;
	}
}

void	get_first_map(t_state *state, t_turn *first)
{
	int		y;
	char	*line;

	y = 0;
	if (get_next_line(0, &line) <= 0)
		display_error("error: bad Plateau");
	free(line);
	if (!(first->map = ft_memalloc(sizeof(char *) * (state->height + 1))))
		display_error("error: malloc");
	while (y < state->height)
	{
		if (get_next_line(0, &(first->map[y])) <= 0)
			display_error("error: bad Plateau");
		y++;
	}
	first->map[y] = NULL;
}

void	check_vm(t_state *state, t_window *win, t_turn **first
				, t_turn **current)
{
	if (!(*first = ft_memalloc(sizeof(t_turn) + 1)))
		display_error("error: malloc");
	check_header();
	get_player(state);
	get_size(state, win);
	get_first_map(state, *first);
	*current = get_turn(*current, state);
	(*first)->next = *current;
	(*first)->prev = NULL;
	if (*current)
		(*current)->prev = *first;
	state->current = *first;
	init_sdl(win, state);
	create_help_menu(win, state);
	create_start_menu(win, state);
}
