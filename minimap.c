/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:00:17 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/22 14:42:53 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Draw a filled square pixel by pixel
void	draw_square(t_map_info *map, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MM_SCALE)
	{
		j = 0;
		while (j < MM_SCALE)
		{
			ft_mlx_pixel_put(map, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_map_info *map, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MM_PLAYER_SIZE)
	{
		j = 0;
		while (j < MM_PLAYER_SIZE)
		{
			ft_mlx_pixel_put(map, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_player_dir(t_map_info *map)
{
	double	x;
	double	y;
	int		i;

	x = map->player_x * MM_SCALE;
	y = map->player_y * MM_SCALE;
	i = 0;
	while (i < MM_VIEW_LEN)
	{
		ft_mlx_pixel_put(map, x, y, MM_DIR);
		x += map->dir_x;
		y += map->dir_y;
		i++;
	}
}

// Draw the 2D map on top of the 3D view
// map->player_x/y represent the exact center of the player
// ft_mlx_pixel_put draws starting from the top-left corner
// -> fix this by shifing point up and left
void	draw_minimap(t_map_info *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->map_height)
	{
		x = 0;
		while (x < map->map_width)
		{
			if (map->norm_map[y][x] == '0')
				draw_square(map, x * MM_SCALE, y * MM_SCALE, MM_FLOOR);
			else if (map->norm_map[y][x] == '1')
				draw_square(map, x * MM_SCALE, y * MM_SCALE, MM_WALL);
			x++;
		}
		y++;
	}
	draw_player(map, (map->player_x * MM_SCALE) - (MM_PLAYER_SIZE / 2),
		(map->player_y * MM_SCALE) - (MM_PLAYER_SIZE / 2), MM_PLAYER);
	draw_player_dir(map);
}
