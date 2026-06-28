/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:28:00 by mkim2             #+#    #+#             */
/*   Updated: 2026/06/18 15:23:18 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_game *game)
{
	game->img_w = 64;
	game->img_h = 64;
	game->img_wall = mlx_xpm_file_to_image(game->mlx, \
			"textures/wall.xpm", &game->img_w, &game->img_h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, \
			"textures/floor.xpm", &game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, \
			"textures/player.xpm", &game->img_w, &game->img_h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, \
			"textures/collect.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, \
			"textures/exit.xpm", &game->img_w, &game->img_h);
	if (!game->img_wall || !game->img_floor || !game->img_player \
			|| !game->img_collect || !game->img_exit)
	{
		write(2, "Error\nFailed to load texture files\n", 35);
		exit(1);
	}
}

static void	put_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collect, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x, y);
	if ((x / 64) == game->p_x && (y / 64) == game->p_y)
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x, y);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			put_tile(game, game->map[i][j], j * 64, i * 64);
		}
	}
}
