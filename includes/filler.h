/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:03:43 by afoures           #+#    #+#             */
/*   Updated: 2018/05/04 20:10:47 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct s_map	t_map;
typedef struct s_box	t_box;
typedef struct s_piece	t_piece;
typedef struct s_lstpos	t_lstpos;
typedef struct s_point	t_point;

struct			s_lstpos
{
	t_lstpos	*next;
	int			x;
	int			y;
	char		player;
};

struct			s_map
{
	t_box		**score;
	t_box		**tmp;
	char		**current;
	char		**last;
	int			w;
	int			h;
	char		player;
	char		opponent;
	char		end;
};

struct			s_box
{
	int			dist;
	char		who;
};

struct			s_piece
{
	char		**piece;
	int			w;
	int			h;
	int			startw;
	int			starth;
	int			endw;
	int			endh;
};

struct			s_point
{
	int			x;
	int			y;
};

int				get_player(t_map *map);
int				get_map_coord(t_map *map);
int				get_map(t_map *map);
void			get_player_first_pos(t_map *map, t_lstpos **first);
int				get_piece(t_piece *piece);
int				update_map(t_map *map);

int				get_score(t_map *map, t_piece *piece, t_point point);
int				algo(t_map *map, t_piece *piece);
int				secondary_algo(t_map *map, t_piece *piece);

void			recalculate_up(t_map *map, t_point p, int dist, char who);
void			recalculate_right(t_map *map, t_point p, int dist, char who);
void			recalculate_down(t_map *map, t_point p, int dist, char who);
void			recalculate_left(t_map *map, t_point p, int dist, char who);

#endif
