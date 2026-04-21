/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:16:01 by yucchen           #+#    #+#             */
/*   Updated: 2026/04/21 21:05:00 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3d_bonus.h"

// The camera plane is always perpendicular (90 degrees) to the direction vector
// Two vectors are perpendicular if their dot product is 0
// Camera plane's length (0.66) controls the field of view (around 66°)
void	set_math_vectors(t_map_info *map, double dx, double dy)
{
	map->dir_x = dx;
	map->dir_y = dy;
	map->plane_x = -dy * 0.66;
	map->plane_y = dx * 0.66;
}

void	init_player_dir(t_map_info *map)
{
	if (map->player_dir == 'N')
		set_math_vectors(map, 0.0, -1.0);
	else if (map->player_dir == 'S')
		set_math_vectors(map, 0.0, 1.0);
	else if (map->player_dir == 'W')
		set_math_vectors(map, -1.0, 0.0);
	else if (map->player_dir == 'E')
		set_math_vectors(map, 1.0, 0.0);
}

void	ft_free_array(char **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_map_info(t_map_info *map)
{
	if (map->lines)
		ft_free_array(map->lines, map->file_height);
	if (map->map_lines)
		free(map->map_lines);
	if (map->norm_map)
		ft_free_array(map->norm_map, map->map_height);
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->we_path)
		free(map->we_path);
	if (map->ea_path)
		free(map->ea_path);
}

int	main(int argc, char **argv)
{
	t_map_info	map;
	char		*storage;
	int			ret;

	ret = 1;
	storage = NULL;
	if (argc != 2)
		return (printf("Error\nExpected exactly one map path\n"), 1);
	if (!is_valid_map_file(argv[1])
		|| !check_file_height(argv[1], &map, &storage))
		return (1);
	if (read_file(argv[1], &map, &storage) && split_config_and_map(&map)
		&& is_valid_element_count(&map) && store_map_lines(&map)
		&& compute_map_width(&map) && create_map(&map))
	{
		fill_map(&map);
		if (check_player(&map) && check_map(&map))
		{
			init_player_dir(&map);
			if (init_window(&map) && init_image(&map) && init_textures(&map))
				start_game(&map);
			ret = 0;
		}
	}
	return (free_map_info(&map), ret);
}
