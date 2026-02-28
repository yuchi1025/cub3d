/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:02:39 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/28 16:49:50 by yucchen          ###   ########.fr       */
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
// Create a blank image
// Get the memory address of the image 
int	init_image(t_map_info *map)
{
	map->img.img_ptr = mlx_new_image(map->mlx_ptr, SCREEN_W, SCREEN_H);
	if (!map->img.img_ptr)
		return (printf("Error: Image creation failed\n"), 0);
	map->img.addr = mlx_get_data_addr(map->img.img_ptr,
			&map->img.bits_per_pixel, &map->img.line_len, &map->img.endian);
	if (!map->img.addr)
		return (0);
	return (1);
}

// How far did the mouse move from the center
// Multiply by a small decimal so the camera doesn't spin wildly
// Force the mouse back to the center
int	handle_mouse(int x, int y, t_map_info *map)
{
	int	delta_x;

	(void)y;
	delta_x = x - (SCREEN_W / 2);
	if (delta_x != 0)
	{
		rotate_player(map, delta_x * 0.05);
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
