/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:30:11 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/22 13:53:32 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Calculate the exact memory address of the pixel
// Write the color to that memory address
void	ft_mlx_pixel_put(t_map_info *map, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_W || y < 0 || y >= SCREEN_H)
		return ;
	dst = map->img.addr
		+ (y * map->img.line_len + x * (map->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// The RGB Bitshift: rgb[0] = Red, rgb[1] = Green, rgb[2] = Blue
int	get_color(int rgb[3])
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	render_background(t_map_info *map)
{
	int	x;
	int	y;
	int	floor_hex;
	int	ceil_hex;

	floor_hex = get_color(map->floor_color);
	ceil_hex = get_color(map->ceil_color);
	y = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			if (y < SCREEN_H / 2)
				ft_mlx_pixel_put(map, x, y, ceil_hex);
			else
				ft_mlx_pixel_put(map, x, y, floor_hex);
			x++;
		}
		y++;
	}
}

int	get_texture_pixel(t_texture *tex, int x, int y)
{
	char	*pixel;

	if (x < 0)
		x = 0;
	if (x >= tex->width)
		x = tex->width - 1;
	if (y < 0)
		y = 0;
	if (y >= tex->height)
		y = tex->height - 1;
	pixel = tex->addr + (y * tex->line_len + x * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

void	draw_wall_stripe(t_map_info *map, t_ray *ray, int x)
{
	int		y;
	int		tex_y;
	int		color;
	double	step;
	double	tex_pos;

	// How much to increase the texture coordinate per screen pixel
	step = 1.0 * ray->current_tex->height / ray->line_height;
	// Starting texture coordinate
	tex_pos = (ray->draw_start - SCREEN_H / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		color = get_texture_pixel(ray->current_tex, ray->tex_x, tex_y);
		ft_mlx_pixel_put(map, x, y, color);
		y++;
	}
}

int	render_frame(t_map_info *map)
{
	move_player(map);
	render_background(map);
	// Draw the walls over the background
	cast_rays(map);
	draw_minimap(map);
	mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->img.img_ptr,
		0, 0);
	return (0);
}
