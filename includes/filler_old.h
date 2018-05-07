/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:09:21 by afoures           #+#    #+#             */
/*   Updated: 2018/04/11 16:07:31 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include "../libft/includes/libft.h"

# define MAP 0xFF << 24
# define DIAGONAL 0x800000
# define CHECK 0x80000
# define X 0x20000
# define O 0x10000
# define DIST 0xFFFF

typedef struct s_map	t_map;
typedef struct s_box	t_box;
typedef struct s_piece	t_piece;
typedef struct s_point	t_point;

struct			s_map
{
	t_box		**current_score;
	t_box		**tmp_score;
	char		**current_map;
	char		**last_map;
	int			w;
	int			h;
	char		player;
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

void			free_piece(t_piece *p);

int				get_player(t_map *map);
int				get_map(t_map *map);
int				get_piece(t_piece *piece);

int				init_map(t_map *map);

int				algo(t_map *map, t_piece *piece);
void			calculate_dist(t_map *map);
void			recalculate_dist(t_map *tmp, t_piece *p, t_point point);
int				get_score(t_map *map, t_piece *piece, t_point point);

#endif
