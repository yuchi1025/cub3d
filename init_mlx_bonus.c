/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:02:39 by yucchen           #+#    #+#             */
/*   Updated: 2026/04/19 15:21:02 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Initialize MLX and create the window
int	init_window(t_map_info *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		return (printf("Error\nMLX init failed\n"), 0);
	map->window_ptr = mlx_new_window(map->mlx_ptr, SCREEN_W, SCREEN_H, "cub3D");
	if (!map->window_ptr)
		return (printf("Error\nWindow creation failed\n"),
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
		return (printf("Error\nImage creation failed\n"),
			mlx_destroy_window(map->mlx_ptr, map->window_ptr),
			mlx_destroy_display(map->mlx_ptr), free(map->mlx_ptr), 0);
	map->img.addr = mlx_get_data_addr(map->img.img_ptr,
			&map->img.bits_per_pixel, &map->img.line_len, &map->img.endian);
	if (!map->img.addr)
		return (printf("Error\nGet image data failed\n"),
			mlx_destroy_image(map->mlx_ptr, map->img.img_ptr),
			mlx_destroy_window(map->mlx_ptr, map->window_ptr),
			mlx_destroy_display(map->mlx_ptr), free(map->mlx_ptr), 0);
	return (1);
}

int	handle_mouse(int x, int y, t_map_info *map)
{
	int	delta_x;

	if (x > SCREEN_W || y > SCREEN_H)
		return (0);
	delta_x = x - map->mouse_prev_x;
	if (delta_x != 0)
		rotate_player(map, delta_x);
	map->mouse_prev_x = x;
	return (0);
}

void	start_game(t_map_info *map)
{
	map->mouse_prev_x = (int)(SCREEN_W / 2);
	mlx_hook(map->window_ptr, DestroyNotify, StructureNotifyMask, ft_close,
		map);
	mlx_hook(map->window_ptr, KeyPress, KeyPressMask, ft_keypress, map);
	mlx_hook(map->window_ptr, KeyRelease, KeyReleaseMask, ft_keyrelease, map);
	mlx_hook(map->window_ptr, MotionNotify, PointerMotionMask, handle_mouse,
		map);
	mlx_loop_hook(map->mlx_ptr, render_frame, map);
	mlx_loop(map->mlx_ptr);
}
