/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:47:16 by yucchen           #+#    #+#             */
/*   Updated: 2026/04/06 14:43:17 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Locate Map Start
static int	is_map_char(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_map_char(line[i]))
			return (0);
		i++;
	}
	return (1);
}

// Check if the top row contains any `0`, `N`, `S`, `W`, `E` -> fail
static int	handle_config_mode(char *line, t_map_info *map, int i, int *in_map)
{
	if (is_blank_line(line))
		return (1);
	if (is_config_line(line))
	{
		if (!check_element(line, map))
			return (0);
		return (1);
	}
	if (is_map_line(line))
	{
		map->map_start = i;
		*in_map = 1;
		if (contain_open_tile(line))
			return (printf("Error\nInvalid top row \"%s\"\n", line), 0);
		return (1);
	}
	return (printf("Error\nInvalid line \"%s\"\n", line), 0);
}

int	split_config_and_map(t_map_info *map)
{
	int		i;
	int		in_map;
	char	*line;

	i = 0;
	in_map = 0;
	while (i < map->file_height)
	{
		line = map->lines[i];
		if (!in_map)
		{
			if (!handle_config_mode(line, map, i, &in_map))
				return (0);
		}
		else if (is_blank_line(line))
			return (printf("Error\nNo blank line allowed inside the map\n"), 0);
		else if (!is_map_line(line))
			return (printf("Error\nInvalid map line \"%s\"\n", line), 0);
		i++;
	}
	if (!in_map)
		return (printf("Error\nNo map line\n"), 0);
	return (1);
}

// Step 5 - Collect Map Lines
// Check if the bottom row contains any `0`, `N`, `S`, `W`, `E` -> fail
int	store_map_lines(t_map_info *map)
{
	int	i;
	int	j;

	map->map_height = map->file_height - map->map_start;
	map->map_lines = malloc((map->map_height + 1) * sizeof(char *));
	if (!map->map_lines)
	{
		printf("Error\nMalloc failed\n");
		return (0);
	}
	i = 0;
	j = map->map_start;
	while (j < map->file_height)
	{
		map->map_lines[i] = map->lines[j];
		i++;
		j++;
	}
	map->map_lines[i] = NULL;
	if (contain_open_tile(map->map_lines[map->map_height - 1]))
		return (printf("Error\nInvalid bottom row \"%s\"\n",
				map->map_lines[map->map_height - 1]), 0);
	return (1);
}
