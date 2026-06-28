/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:24:55 by mkim2             #+#    #+#             */
/*   Updated: 2026/06/18 15:15:06 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC				65307
# define KEY_W					119
# define KEY_A					97
# define KEY_S					115
# define KEY_D					100

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;

	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	int		img_w;
	int		img_h;

	int		p_x;
	int		p_y;
	int		moves;
	int		collect_cnt;
	int 	exit_x;
	int 	exit_y;
}	t_game;

int		close_game(t_game *game);
void	check_filename(char *filename);
int		get_map_height(char *filename);
void	parse_map(t_game *game, char *filename);
void    check_map_validity(t_game *game, char *filename);

int		get_line_len(char *line);
void	check_rectangle(t_game *game);
void	check_walls(t_game *game);
void	check_components(t_game *game);

void	check_valid_path(t_game *game);

void	init_images(t_game *game);
void	render_map(t_game *game);

void	init_game_vars(t_game *game);

#endif