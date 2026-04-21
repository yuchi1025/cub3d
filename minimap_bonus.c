/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:00:17 by yucchen           #+#    #+#             */
/*   Updated: 2026/04/21 19:48:17 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	initialize_mm(t_map_info *map, t_mini *mini)
{
	int	scale_x;
	int	scale_y;

	scale_x = floor(MM_X_MAX / map->map_width);
	scale_y = floor(MM_Y_MAX / map->map_height);
	if (scale_x < scale_y)
		mini->mm_scale = scale_x;
	else
		mini->mm_scale = scale_y;
	mini->player_scale = (int)(mini->mm_scale / 3);
}

// Draw a filled square pixel by pixel
static void	draw_square(t_map_info *map, t_mini *mini, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	if (map->norm_map[y][x] == '0')
		color = MM_FLOOR;
	else if (map->norm_map[y][x] == '1')
		color = MM_WALL;
	else if (map->norm_map[y][x] == ' ')
		color = MM_SPACE;
	while (i < mini->mm_scale)
	{
		j = 0;
		while (j < mini->mm_scale)
		{
			ft_mlx_pixel_put(map, (x * mini->mm_scale) + j,
				(y * mini->mm_scale) + i, color);
			j++;
		}
		i++;
	}
}

static void	draw_player(t_map_info *map, t_mini *mini, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < mini->player_scale * 2)
	{
		j = 0;
		while (j < mini->player_scale * 2)
		{
			if (pow(j - mini->player_scale, 2) + pow(i - mini->player_scale, 2)
				<= pow(mini->player_scale, 2))
				ft_mlx_pixel_put(map, x + j, y + i, MM_PLAYER);
			j++;
		}
		i++;
	}
}

static void	draw_player_dir(t_map_info *map, t_mini *mini)
{
	double	x;
	double	y;
	int		i;

	x = (map->player_x - 0.25) * mini->mm_scale + mini->player_scale / 2;
	y = (map->player_y - 0.25) * mini->mm_scale + mini->player_scale / 2;
	i = 0;
	while (i < mini->player_scale * 1.5)
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
// -> fix this by shifting point up and left
void	draw_minimap(t_map_info *map, t_mini *mini)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->map_height)
	{
		x = 0;
		while (x < map->map_width)
		{
			draw_square(map, mini, x, y);
			x++;
		}
		y++;
	}
	draw_player(map, mini, ((map->player_x - 0.25) * mini->mm_scale)
		- (mini->player_scale / 2), ((map->player_y - 0.25) * mini->mm_scale)
		- (mini->player_scale / 2));
	draw_player_dir(map, mini);
}
