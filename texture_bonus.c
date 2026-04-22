/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sileow <sileow@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:30:22 by yucchen           #+#    #+#             */
/*   Updated: 2026/04/22 17:00:16 by sileow           ###   ########.fr       */
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
	if (!load_texture(map, &map->no, map->no_path))
		return (printf("Error\nLoad NO failed\n"), 0);
	if (!load_texture(map, &map->so, map->so_path))
		return (printf("Error\nLoad SO failed\n"),
			destroy_texture(map, &map->no), 0);
	if (!load_texture(map, &map->we, map->we_path))
		return (printf("Error\nLoad WE failed\n"),
			destroy_texture(map, &map->no), destroy_texture(map, &map->so), 0);
	if (!load_texture(map, &map->ea, map->ea_path))
		return (printf("Error\nLoad EA failed\n"),
			destroy_texture(map, &map->no), destroy_texture(map, &map->so),
			destroy_texture(map, &map->we), 0);
	if (!load_texture(map, &map->ew_off, "./textures/ew_off.xpm"))
		return (printf("Error\nLoad ew_off failed\n"),
			destroy_texture(map, &map->no), destroy_texture(map, &map->so),
			destroy_texture(map, &map->we), destroy_texture(map, &map->ea), 0);
	if (!load_texture(map, &map->n_lit, "./textures/n_lit.xpm"))
		return (printf("Error\nLoad n_lit failed\n"),
			destroy_texture(map, &map->no), destroy_texture(map, &map->so),
			destroy_texture(map, &map->we), destroy_texture(map, &map->ea),
			destroy_texture(map, &map->ew_off), 0);
	return (1);
}
