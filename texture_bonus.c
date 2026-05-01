/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:30:22 by yucchen           #+#    #+#             */
/*   Updated: 2026/05/01 16:32:11 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	load_texture(t_map_info *map, t_texture *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			path, &tex->width, &tex->height);
	if (!tex->img_ptr)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bits_per_pixel,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
		return (mlx_destroy_image(map->mlx_ptr, tex->img_ptr),
			tex->img_ptr = NULL, 0);
	return (1);
}

static void	destroy_texture(t_map_info *map, t_texture *tex)
{
	if (tex->img_ptr)
	{
		mlx_destroy_image(map->mlx_ptr, tex->img_ptr);
		tex->img_ptr = NULL;
	}
}

int	init_textures(t_map_info *map)
{
	load_texture(map, &map->no, map->no_path);
	load_texture(map, &map->so, map->so_path);
	load_texture(map, &map->we, map->we_path);
	load_texture(map, &map->ea, map->ea_path);
	load_texture(map, &map->ew_off, "./textures/ew_off.xpm");
	load_texture(map, &map->n_lit, "./textures/n_lit.xpm");
	load_texture(map, &map->door, "./textures/door.xpm");
	if (!map->no.addr || !map->so.addr || !map->we.addr || !map->ea.addr
		|| !map->ew_off.addr || !map->n_lit.addr || !map->door.addr)
		return (printf("Error\nLoad texture failed\n"),
			destroy_texture(map, &map->no), destroy_texture(map, &map->so),
			destroy_texture(map, &map->we), destroy_texture(map, &map->ea),
			destroy_texture(map, &map->ew_off),
			destroy_texture(map, &map->n_lit), 0);
	return (1);
}
