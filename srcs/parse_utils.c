/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:23:39 by mkim2             #+#    #+#             */
/*   Updated: 2026/06/18 11:57:39 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int	get_line_len(char *line)
{
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	return (len);
}

void	check_rectangle(t_game *game)
{
	int	i;

	game->map_width = get_line_len(game->map[0]);
	i = 1;
	while (i < game->map_height)
	{
		if (get_line_len(game->map[i]) != game->map_width)
		{
			write(2, "Error\nMap is not rectangular\n", 29);
			exit(1);
		}
		i++;
	}
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		if (i == 0 || i == game->map_height - 1)
		{
			j = -1;
			while (++j < game->map_width)
			{
				if (game->map[i][j] != '1')
				{
					write(2, "Error\nMap must be surrounded by walls\n", 38);
					exit(1);
				}
			}
		}
		else if (game->map[i][0] != '1' || \
						game->map[i][game->map_width - 1] != '1')
		{
			write(2, "Error\nMap must be surrounded by walls\n", 38);
			exit(1);
		}
	}
}

static void	count_components(char c, int *p, int *e, int *char_c)
{
	if (c == 'P')
		(*p)++;
	else if (c == 'E')
		(*e)++;
	else if (c == 'C')
		(*char_c)++;
	else if (c != '0' && c != '1' && c != '\n')
	{
		write(2, "Error\nInvalid character in map\n", 31);
		exit(1);
	}
}

void	check_components(t_game *game)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
			count_components(game->map[i][j], &p, &e, &c);
	}
	if (p != 1 || e != 1 || c < 1)
	{
		write(2, "Error\nMap must have 1 P, 1 E, and at least 1 C\n", 47);
		exit(1);
	}
}
