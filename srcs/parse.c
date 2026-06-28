/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:13:22 by mkim2             #+#    #+#             */
/*   Updated: 2026/06/18 11:26:27 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

void	check_filename(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
	{
		write(2, "Error\nInvalid file extension. Use .ber\n", 39);
		exit(1);
	}
}

int	get_map_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nFailed to open file\n", 26);
		exit(1);
	}
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	fill_map(t_game *game, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nFailed to open file in fill_map\n", 38);
		exit(1);
	}
	i = 0;
	while (i < game->map_height)
	{
		line = get_next_line(fd);
		game->map[i] = line;
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}

void	parse_map(t_game *game, char *filename)
{
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
	{
		write(2, "Error\nMalloc failed for map\n", 28);
		exit(1);
	}
	fill_map(game, filename);
}

void	check_map_validity(t_game *game, char *filename)
{
	check_filename(filename);
	game->map_height = get_map_height(filename);
	parse_map(game, filename);
	check_rectangle(game);
	check_walls(game);
	check_components(game);
	check_valid_path(game);
	init_game_vars(game);
}
