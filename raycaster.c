/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:57:23 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/19 15:59:29 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Calculate step and initial sideDist
void	calculate_step(t_ray *ray, t_map_info *map)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (map->player_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - map->player_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (map->player_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - map->player_y)
			* ray->delta_dist_y;
	}
}

// The ray starts at the position of the player
void	init_ray(t_ray *ray, t_map_info *map, int x)
{
	// Calculate ray position and direction
	// camera_x goes form -1 (left side of screen) to +1 (right side of screen)
	ray->camera_x = 2 * x / (double)SCREEN_W - 1;
	ray->ray_dir_x = map->dir_x + map->plane_x * ray->camera_x;
	ray->ray_dir_y = map->dir_y + map->plane_y * ray->camera_x;
	// Which box of the map is the player in
	ray->map_x = (int)map->player_x;
	ray->map_y = (int)map->player_y;
	// Length of ray from one x or y-side to next x or y-side
	ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
	ray->hit = 0;
	calculate_step(ray, map);
}

// Jump to next map square, either in x-direction, or in y-direction
// Check if ray has hit a wall
void	perform_dda(t_ray *ray, t_map_info *map)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->norm_map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calculate_wall_height(t_ray *ray)
{
	// Calculate distance projected on camera direction
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	// Calculate height of line to draw on screen
	ray->line_height = (int)(SCREEN_H / ray->perp_wall_dist);
	// Calculate lowest and highest pixel to fill in current stripe
	ray->draw_start = -ray->line_height / 2 + SCREEN_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_H / 2;
	if (ray->draw_end >= SCREEN_H)
		ray->draw_end = SCREEN_H - 1;
}

void	draw_wall_stripe(t_map_info *map, t_ray *ray, int x)
{
	int	y;
	int	color;

	// TODO: Simple color for now
	if (ray->side == 0)
		color = 0xFF0000;
	else
		color = 0xAA0000;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		ft_mlx_pixel_put(map, x, y, color);
		y++;
	}
}

void	cast_rays(t_map_info *map)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < SCREEN_W)
	{
		init_ray(&ray, map, x);
		perform_dda(&ray, map);
		calculate_wall_height(&ray);
		draw_wall_stripe(map, &ray, x);
		x++;
	}
}
