/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:30:22 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/20 19:43:27 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_texture(t_map_info *map, t_texture *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			path, &tex->width, &tex->height);
	if (!tex->img_ptr)
		return (printf("Error: Failed to load texture\n"), 0);
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bits_per_pixel,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
		return (0);
	return (1);
}

int	init_textures(t_map_info *map)
{
	if (!load_texture(map, &map->no, map->no_path))
		return (printf("Error: Load NO failed\n"), 0);
	if (!load_texture(map, &map->so, map->so_path))
		return (printf("Error: Load SO failed\n"), 0);
	if (!load_texture(map, &map->we, map->we_path))
		return (printf("Error: Load WE failed\n"), 0);
	if (!load_texture(map, &map->ea, map->ea_path))
		return (printf("Error: Load EA failed\n"), 0);
	return (1);
}
