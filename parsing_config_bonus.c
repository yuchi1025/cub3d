/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_config_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:20:51 by yucchen           #+#    #+#             */
/*   Updated: 2026/04/21 21:05:39 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3d_bonus.h"

static void	save_texture(int *cnt, char **dest, char *path)
{
	(*cnt)++;
	if (*cnt == 1)
		*dest = ft_strdup(path);
}

static int	check_texture(char *id, char *path, t_map_info *map)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror("open error"), 0);
	close(fd);
	if (ft_strcmp(id, "NO") == 0)
		save_texture(&(map->no_cnt), &(map->no_path), path);
	else if (ft_strcmp(id, "SO") == 0)
		save_texture(&(map->so_cnt), &(map->so_path), path);
	else if (ft_strcmp(id, "WE") == 0)
		save_texture(&(map->we_cnt), &(map->we_path), path);
	else if (ft_strcmp(id, "EA") == 0)
		save_texture(&(map->ea_cnt), &(map->ea_path), path);
	else
		return (printf("Error\nInvalid texture id \"%s\"\n", id), 0);
	return (1);
}

static int	save_rgb(char *id, char **color, t_map_info *map)
{
	int	n;

	n = 0;
	while (color[n])
	{
		if (!is_number_in_range(color[n]))
			return (0);
		if (ft_strcmp(id, "F") == 0)
			map->floor_color[n] = ft_atoi(color[n]);
		else
			map->ceil_color[n] = ft_atoi(color[n]);
		n++;
	}
	if (n != 3)
		return (printf("Error\nOnly accept 3 numbers\n"), 0);
	return (1);
}

static int	check_color(char *id, char *colors, t_map_info *map)
{
	char	**color;

	if (ft_strcmp(id, "F") == 0)
		(map->floor_cnt)++;
	else if (ft_strcmp(id, "C") == 0)
		(map->ceil_cnt)++;
	else
		return (printf("Error\nInvalid color id \"%s\"\n", id), 0);
	if (!check_commas(colors))
		return (0);
	color = ft_split(colors, ',');
	if (!color)
		return (printf("Error\nMalloc failed\n"), 0);
	if (!save_rgb(id, color, map))
		return (free_split(color), 0);
	return (free_split(color), 1);
}

int	check_element(char *line, t_map_info *map)
{
	char	**token;
	int		n;

	token = ft_split(line, ' ');
	if (!token)
		return (printf("Error\nMalloc failed\n"), 0);
	n = 0;
	while (token[n])
		n++;
	if (n != 2)
		return (printf("Error\nWrong element info\n"), free_split(token), 0);
	if (ft_strlen(token[0]) == 2)
	{
		if (!check_texture(token[0], token[1], map))
			return (free_split(token), 0);
	}
	else if (ft_strlen(token[0]) == 1)
	{
		if (!check_color(token[0], token[1], map))
			return (free_split(token), 0);
	}
	else
		return (printf("Error\nInvalid id \"%s\"\n", token[0]),
			free_split(token), 0);
	return (free_split(token), 1);
}
