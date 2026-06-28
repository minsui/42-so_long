/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:25:23 by mkim2             #+#    #+#             */
/*   Updated: 2026/06/17 20:05:15 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

static void	find_player(t_game *game, int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
		}
	}
}

static void	flood_fill(t_game *game, char **temp_map, int x, int y)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return ;
	if (temp_map[y][x] == '1' || temp_map[y][x] == 'X')
		return ;
	temp_map[y][x] = 'X';
	flood_fill(game, temp_map, x + 1, y);
	flood_fill(game, temp_map, x - 1, y);
	flood_fill(game, temp_map, x, y + 1);
	flood_fill(game, temp_map, x, y - 1);
}

static void	check_remains(t_game *game, char **temp_map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (temp_map[i][j] == 'C' || temp_map[i][j] == 'E')
			{
				write(2, "Error\nNo valid path in map\n", 27);
				exit(1);
			}
		}
	}
}

void	check_valid_path(t_game *game)
{
	char	**temp_map;
	int		p_x;
	int		p_y;
	int		i;

	temp_map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!temp_map)
		exit(1);
	i = -1;
	while (++i < game->map_height)
		temp_map[i] = ft_strdup(game->map[i]);
	temp_map[i] = NULL;
	find_player(game, &p_x, &p_y);
	flood_fill(game, temp_map, p_x, p_y);
	check_remains(game, temp_map);
	i = -1;
	while (temp_map[++i])
		free(temp_map[i]);
	free(temp_map);
}

void	init_game_vars(t_game *game)
{
	int	i;
	int	j;

	game->moves = 0;
	game->collect_cnt = 0;
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->p_x = j;
				game->p_y = i;
			}
			else if (game->map[i][j] == 'C')
				game->collect_cnt++;
		}
	}
}
