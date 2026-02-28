/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:57:23 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/28 17:55:14 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	calculate_texture_x(t_ray *ray, t_map_info *map)
{
	double	wall_x; // Where the wall was hit

	// Calculate value of wall_x
	if (ray->side == 0)
		wall_x = map->player_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = map->player_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->current_tex = &map->no;
	else if (ray->side == 1 && ray->ray_dir_y > 0)
		ray->current_tex = &map->so;
	else if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->current_tex = &map->ea;
	else
		ray->current_tex = &map->we;
	ray->tex_x = (int)(wall_x * (double)ray->current_tex->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = ray->current_tex->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = ray->current_tex->width - ray->tex_x - 1;
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
		calculate_texture_x(&ray, map);
		draw_wall_stripe(map, &ray, x);
		x++;
	}
}
