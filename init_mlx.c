/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:02:39 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/19 16:03:59 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Initialize MLX and create the window
int	init_window(t_map_info *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		return (printf("Error: MLX init failed\n"), 0);
	map->window_ptr = mlx_new_window(map->mlx_ptr, SCREEN_W, SCREEN_H, "cub3D");
	if (!map->window_ptr)
		return (printf("Error: Window creation failed\n"),
			mlx_destroy_display(map->mlx_ptr), free(map->mlx_ptr), 0);
	return (1);
}

// Create the image buffer
int	init_image(t_map_info *map)
{
	// Create a blank image
	map->img_ptr = mlx_new_image(map->mlx_ptr, SCREEN_W, SCREEN_H);
	if (!map->img_ptr)
		return (printf("Error: Image creation failed\n"), 0);
	// Get the memory address of the image 
	map->addr = mlx_get_data_addr(map->img_ptr, &map->bits_per_pixel,
			&map->line_len, &map->endian);
	return (1);
}

int	ft_close(t_map_info *map)
{
	if (map)
	{
		if (map->img_ptr)
			mlx_destroy_image(map->mlx_ptr, map->img_ptr);
		if (map->window_ptr)
			mlx_destroy_window(map->mlx_ptr, map->window_ptr);
		if (map->mlx_ptr)
		{
			mlx_destroy_display(map->mlx_ptr);
			free(map->mlx_ptr);
		}
		free_map_info(map);
	}
	exit(0);
	return (0);
}

int	ft_keypress(int keycode, t_map_info *map)
{
	if (keycode == KEY_ESC)
		ft_close(map);
	else if (keycode == KEY_W)
		map->key_w = 1;
	else if (keycode == KEY_A)
		map->key_a = 1;
	else if (keycode == KEY_S)
		map->key_s = 1;
	else if (keycode == KEY_D)
		map->key_d = 1;
	else if (keycode == KEY_LEFT)
		map->key_left = 1;
	else if (keycode == KEY_RIGHT)
		map->key_right = 1;
	return (0);
}

int	ft_keyrelease(int keycode, t_map_info *map)
{
	if (keycode == KEY_W)
		map->key_w = 0;
	else if (keycode == KEY_A)
		map->key_a = 0;
	else if (keycode == KEY_S)
		map->key_s = 0;
	else if (keycode == KEY_D)
		map->key_d = 0;
	else if (keycode == KEY_LEFT)
		map->key_left = 0;
	else if (keycode == KEY_RIGHT)
		map->key_right = 0;
	return (0);
}

// Calculate the exact memory address of the pixel
// Write the color to that memory address
void	ft_mlx_pixel_put(t_map_info *map, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_W || y < 0 || y >= SCREEN_H)
		return ;
	dst = map->addr + (y * map->line_len + x * (map->bits_per_pixel / 8));
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

int	render_frame(t_map_info *map)
{
	move_player(map);
	render_background(map);
	// Draw the walls over the background
	cast_rays(map);
	mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->img_ptr, 0, 0);
	return (0);
}

void	start_game(t_map_info *map)
{
	mlx_hook(map->window_ptr, DestroyNotify, StructureNotifyMask, ft_close,
		map);
	mlx_hook(map->window_ptr, KeyPress, KeyPressMask, ft_keypress, map);
	mlx_hook(map->window_ptr, KeyRelease, KeyReleaseMask, ft_keyrelease, map);
	mlx_loop_hook(map->mlx_ptr, render_frame, map);
	mlx_loop(map->mlx_ptr);
}
