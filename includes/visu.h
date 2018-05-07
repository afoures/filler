/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:14:15 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 15:40:14 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <SDL.h>
# include <SDL_mixer.h>
# include <SDL_ttf.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

# define NIGHT 0x000000
# define P1_DAY 0xE60F00
# define P1_NIGHT 0x8000FF
# define P2_DAY 0x1A1AFF
# define P2_NIGHT 0x00EE00
# define P1_LST_DAY 0xFFCCCC
# define P1_LST_NIGHT 0xFFCCFF
# define P2_LST_DAY 0x99FFF5
# define P2_LST_NIGHT 0xDDFFDD

typedef struct s_window	t_window;
typedef struct s_state	t_state;
typedef struct s_turn	t_turn;
typedef struct s_rect	t_rect;
typedef struct s_point	t_point;
typedef union u_color	t_color;

struct				s_window
{
	SDL_Window	*window;
	SDL_Surface	*surface;
	SDL_Surface	*help;
	Mix_Music	*tetris;
	Mix_Music	*darude;
	Mix_Music	*esaxguy;
	Mix_Music	*nggyu;
	TTF_Font	*ttf_help;
	TTF_Font	*ttf_winner;
	SDL_Event	event;
	int			width;
	int			height;
};

struct				s_point
{
	int				x;
	int				y;
};

struct				s_state
{
	double			k;
	t_turn			*current;
	char			*p1;
	char			*p2;
	int				width;
	int				height;
	int				square_size;
	int				game_started;
	int				game_finished;
	int				pause;
	int				speed;
	int				tab;
	int				score1;
	int				score2;
};

struct				s_turn
{
	char			**map;
	int				skip;
	t_turn			*next;
	t_turn			*prev;
};

struct				s_rect
{
	int				x;
	int				y;
	int				width;
	int				heigth;
};

union				u_color
{
	int				color;
	unsigned char	rgb[4];
};

Uint32				get_color(t_color c1, t_color c2, double k);
void				get_event(t_window *win, t_state *state, t_turn *first);
void				put_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
void				put_rect(SDL_Surface *surface, t_rect rectangle
							, Uint32 pixel);
void				put_text(SDL_Surface *surface, SDL_Surface *text, int x
							, int y);
void				put_line(SDL_Surface *surface, t_point start, t_point end
							, Uint32 pixel);
void				clean_quit(t_window *win);
void				display_error(char *error);

t_turn				*get_turn(t_turn *actual, t_state *state);

SDL_Color			argb_to_sdl(Uint32 color);

void				init_sdl(t_window *win, t_state *state);

void				create_start_menu(t_window *win, t_state *state);

void				create_help_menu(t_window *win, t_state *state);
void				check_vm(t_state *state, t_window *win, t_turn **first
							, t_turn **current);

void				draw_current(t_window *win, t_state *state);
void				draw_next(t_window *win, t_state *state);
void				draw_prev(t_window *win, t_state *state);
void				draw_help(t_window *win, t_state *state, int skipline);
void				put_winner(t_window *win, t_state *state);

void				draw_piece(t_window *win, t_state *state, t_point coord
							, int who);
void				draw_lst_piece(t_window *win, t_state *state, t_point coord
							, int who);

#endif
