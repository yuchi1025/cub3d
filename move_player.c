/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:45:05 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/19 15:58:35 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Move forward/backward if no wall in front of/behind
void	move_forward_backward(t_map_info *map, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = map->player_x + map->dir_x * move_speed;
	new_y = map->player_y + map->dir_y * move_speed;
	if (map->norm_map[(int)map->player_y][(int)new_x] != '1')
		map->player_x = new_x;
	if (map->norm_map[(int)new_y][(int)map->player_x] != '1')
		map->player_y = new_y;
}

// Move left/right if no wall
void	move_left_right(t_map_info *map, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = map->player_x + map->plane_x * move_speed;
	new_y = map->player_y + map->plane_y * move_speed;
	if (map->norm_map[(int)map->player_y][(int)new_x] != '1')
		map->player_x = new_x;
	if (map->norm_map[(int)new_y][(int)map->player_x] != '1')
		map->player_y = new_y;
}

// Rotate to the right/left
// Both camera direction and camera plane must be rotated
void	rotate_player(t_map_info *map, double i)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = map->dir_x;
	map->dir_x = map->dir_x * cos(i * ROT_SPEED)
		- map->dir_y * sin(i * ROT_SPEED);
	map->dir_y = old_dir_x * sin(i * ROT_SPEED)
		+ map->dir_y * cos(i * ROT_SPEED);
	old_plane_x = map->plane_x;
	map->plane_x = map->plane_x * cos(i * ROT_SPEED)
		- map->plane_y * sin(i * ROT_SPEED);
	map->plane_y = old_plane_x * sin(i * ROT_SPEED)
		+ map->plane_y * cos(i * ROT_SPEED);
}

void	move_player(t_map_info *map)
{
	if (map->key_w)
		move_forward_backward(map, MOVE_SPEED);
	if (map->key_s)
		move_forward_backward(map, -MOVE_SPEED);
	if (map->key_a)
		move_left_right(map, -MOVE_SPEED);
	if (map->key_d)
		move_left_right(map, MOVE_SPEED);
	if (map->key_left)
		rotate_player(map, -1);
	if (map->key_right)
		rotate_player(map, 1);
}
