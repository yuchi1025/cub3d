/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:33:12 by yucchen           #+#    #+#             */
/*   Updated: 2026/04/06 15:11:11 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	contain_open_tile(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
			return (1);
		i++;
	}
	return (0);
}

// Step 4 - Check Configuration Identifiers Count 
int	is_valid_element_count(t_map_info *map)
{
	if (map->no_cnt != 1)
		return (printf("Error\nInvalid tex_NO count: %d\n", map->no_cnt), 0);
	if (map->so_cnt != 1)
		return (printf("Error\nInvalid tex_SO count: %d\n", map->so_cnt), 0);
	if (map->we_cnt != 1)
		return (printf("Error\nInvalid tex_WE count: %d\n", map->we_cnt), 0);
	if (map->ea_cnt != 1)
		return (printf("Error\nInvalid tex_EA count: %d\n", map->ea_cnt), 0);
	if (map->floor_cnt != 1)
		return (printf("Error\nInvalid floor count: %d\n", map->floor_cnt), 0);
	if (map->ceil_cnt != 1)
		return (printf("Error\nInvalid ceil count: %d\n", map->ceil_cnt), 0);
	return (1);
}

int	is_open_tile(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

// Step 9 - Map Validation
static int	check_neighbors(t_map_info *map, int x, int y)
{
	if (y > 0 && map->norm_map[y - 1][x] == ' ')
		return (0);
	if (y + 1 < map->map_height && map->norm_map[y + 1][x] == ' ')
		return (0);
	if (x > 0 && map->norm_map[y][x - 1] == ' ')
		return (0);
	if (x + 1 < map->map_width && map->norm_map[y][x + 1] == ' ')
		return (0);
	return (1);
}

int	check_map(t_map_info *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (map->norm_map[i][j] == '0')
			{
				if (!check_neighbors(map, j, i))
				{
					printf("Error\nInvalid map\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}
