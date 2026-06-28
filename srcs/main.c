/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:32:07 by mkim2             #+#    #+#             */
/*   Updated: 2026/06/18 16:05:24 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int	close_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

static void	print_moves(t_game *game)
{
	char	*moves_str;

	game->moves++;
	moves_str = ft_itoa(game->moves);
	write(1, "Moves: ", 7);
	write(1, moves_str, ft_strlen(moves_str));
	write(1, "\n", 1);
	free(moves_str);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'E' && game->collect_cnt == 0)
		close_game(game);
	if (game->map[new_y][new_x] == 'C')
	{
		game->collect_cnt--;
		game->map[new_y][new_x] = '0';
	}
	game->p_x = new_x;
	game->p_y = new_y;
	print_moves(game);
	render_map(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		move_player(game, game->p_x, game->p_y - 1);
	else if (keycode == KEY_S)
		move_player(game, game->p_x, game->p_y + 1);
	else if (keycode == KEY_A)
		move_player(game, game->p_x - 1, game->p_y);
	else if (keycode == KEY_D)
		move_player(game, game->p_x + 1, game->p_y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error\nUsage: ./so_long <map_file.ber>\n", 38);
		return (1);
	}
	check_map_validity(&game, argv[1]);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, game.map_width * 64, \
			game.map_height * 64, "so_long");
	init_images(&game);
	render_map(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 1L << 17, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
