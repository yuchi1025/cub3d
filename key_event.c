/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:54:10 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/28 15:02:02 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
