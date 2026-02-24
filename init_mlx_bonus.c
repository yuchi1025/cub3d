/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:02:39 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/24 14:20:44 by yucchen          ###   ########.fr       */
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
	map->img.img_ptr = mlx_new_image(map->mlx_ptr, SCREEN_W, SCREEN_H);
	if (!map->img.img_ptr)
		return (printf("Error: Image creation failed\n"), 0);
	// Get the memory address of the image 
	map->img.addr = mlx_get_data_addr(map->img.img_ptr,
			&map->img.bits_per_pixel, &map->img.line_len, &map->img.endian);
	if (!map->img.addr)
		return (0);
	return (1);
}

int	ft_close(t_map_info *map)
{
	if (map)
	{
		if (map->no.img_ptr)
			mlx_destroy_image(map->mlx_ptr, map->no.img_ptr);
		if (map->so.img_ptr)
			mlx_destroy_image(map->mlx_ptr, map->so.img_ptr);
		if (map->we.img_ptr)
			mlx_destroy_image(map->mlx_ptr, map->we.img_ptr);
		if (map->ea.img_ptr)
			mlx_destroy_image(map->mlx_ptr, map->ea.img_ptr);
		if (map->img.img_ptr)
			mlx_destroy_image(map->mlx_ptr, map->img.img_ptr);
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

int	handle_mouse(int x, int y, t_map_info *map)
{
	int	delta_x;

	(void)y;
	// How far did the mouse move from the center
	delta_x = x - (SCREEN_W / 2);
	if (delta_x != 0)
	{
		// Multiply by a small decimal so the camera doesn't spin wildly
		rotate_player(map, delta_x * 0.05);
		// Force the mouse back to the center
		mlx_mouse_move(map->mlx_ptr, map->window_ptr,
			SCREEN_W / 2, SCREEN_H / 2);
	}
	return (0);
}

void	start_game(t_map_info *map)
{
	mlx_hook(map->window_ptr, DestroyNotify, StructureNotifyMask, ft_close,
		map);
	mlx_hook(map->window_ptr, KeyPress, KeyPressMask, ft_keypress, map);
	mlx_hook(map->window_ptr, KeyRelease, KeyReleaseMask, ft_keyrelease, map);
	mlx_hook(map->window_ptr, MotionNotify, PointerMotionMask, handle_mouse,
		map);
	mlx_mouse_hide(map->mlx_ptr, map->window_ptr);
	mlx_loop_hook(map->mlx_ptr, render_frame, map);
	mlx_loop(map->mlx_ptr);
}
