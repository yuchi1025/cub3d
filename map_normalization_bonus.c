/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_normalization_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:47:20 by yucchen           #+#    #+#             */
/*   Updated: 2026/04/21 21:05:12 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3d_bonus.h"

// Step 6 - Compute Map Dimensions
// Check if the first/last column contains any `0`, `N`, `S`, `W`, `E` -> fail
int	compute_map_width(t_map_info *map)
{
	int	i;
	int	line_width;

	i = 0;
	while (i < map->map_height)
	{
		line_width = ft_strlen(map->map_lines[i]);
		if (is_open_tile(map->map_lines[i][0]))
		{
			printf("Error\nInvalid left column\n");
			return (0);
		}
		if (is_open_tile(map->map_lines[i][line_width - 1]))
		{
			printf("Error\nInvalid right column\n");
			return (0);
		}
		if (line_width > map->map_width)
			map->map_width = line_width;
		i++;
	}
	return (1);
}

// Step 7 - Normalize map
int	create_map(t_map_info *map)
{
	int	i;
	int	j;

	map->norm_map = malloc((map->map_height + 1) * sizeof(char *));
	if (!map->norm_map)
		return (printf("Error\nMalloc failed\n"), 0);
	i = 0;
	while (i < map->map_height)
	{
		map->norm_map[i] = malloc(map->map_width + 1);
		if (!map->norm_map[i])
			return (ft_free_array(map->norm_map, i),
				printf("Error\nMalloc failed\n"), 0);
		j = 0;
		while (j < map->map_width)
		{
			map->norm_map[i][j] = ' ';
			j++;
		}
		map->norm_map[i][map->map_width] = '\0';
		i++;
	}
	map->norm_map[map->map_height] = NULL;
	return (1);
}

void	fill_map(t_map_info *map)
{
	int	i;
	int	j;
	int	line_width;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		line_width = ft_strlen(map->map_lines[i]);
		while (j < line_width)
		{
			(map->norm_map)[i][j] = (map->map_lines)[i][j];
			j++;
		}
		i++;
	}
}

// Step 8 - Player Extraction
static int	set_player(t_map_info *map, int i, int j, int *find_player)
{
	if (*find_player != 0)
		return (printf("Error\nOnly one player allowed\n"), 0);
	*find_player = 1;
	map->player_x = j + 0.5;
	map->player_y = i + 0.5;
	map->player_dir = map->norm_map[i][j];
	map->norm_map[i][j] = '0';
	return (1);
}

int	check_player(t_map_info *map)
{
	int	i;
	int	j;
	int	find_player;

	i = 0;
	find_player = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (ft_strchr("NSWE", map->norm_map[i][j]))
			{
				if (!set_player(map, i, j, &find_player))
					return (0);
			}
			j++;
		}
		i++;
	}
	if (find_player == 0)
		return (printf("Error\nNo player found\n"), 0);
	return (1);
}
