/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:16:01 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/20 19:39:05 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3d.h"

//// Step 1 - File validation
//int	is_valid_map_file(char *path)
//{
//	char	*map;
//	int		len;
//	int		fd;
//
//	if (!path || path[0] == '\0')
//		return (printf("Error: Empty path\n"), 0);
//	map = ft_strrchr(path, '/');
//	if (map)
//		map++;
//	else
//		map = path;
//	len = ft_strlen(map);
//	if (len < 5 || ft_strncmp(map + len - 4, ".cub", 4) != 0)
//		return (printf("Error: Map should in format *.cub\n"), 0);
//	fd = open(path, O_RDONLY);
//	if (fd == -1)
//		return (perror("open error"), 0);
//	close(fd);
//	return (1);
//}

//// Step 2 - Read file into lines
//int	check_file_height(const char *path, t_map_info *map, char **storage)
//{
//	int		fd;
//	char	*next_line;
//
//	ft_bzero(map, sizeof(*map));
//	fd = open(path, O_RDONLY);
//	if (fd == -1)
//		return (perror("open error"), 0);
//	next_line = get_next_line(fd, storage);
//	while (next_line)
//	{
//		free(next_line);
//		(map->file_height)++;
//		next_line = get_next_line(fd, storage);
//	}
//	close(fd);
//	if (map->file_height == 0)
//		return (printf("Error: Empty file\n"), 0);
//	return (1);
//}

//int	read_file(const char *path, t_map_info *map, char **storage)
//{
//	int		i;
//	int		fd;
//	char	*next_line;
//	int		len;
//
//	i = 0;
//	fd = open(path, O_RDONLY);
//	if (fd == -1)
//		return (perror("open error"), 0);
//	map->lines = malloc((map->file_height + 1) * sizeof(char *));
//	if (!map->lines)
//		return (printf("Error: Malloc failed\n"), 0);
//	next_line = get_next_line(fd, storage);
//	while (next_line)
//	{
//		len = ft_strlen(next_line);
//		if (len > 0 && next_line[len - 1] == '\n')
//			next_line[len - 1] = '\0';
//		map->lines[i] = next_line;
//		next_line = get_next_line(fd, storage);
//		i++;
//	}
//	map->lines[i] = NULL;
//	close(fd);
//	return (1);
//}

// Step 3 - Parse configuration lines, locate map start & parse map lines
/* 
isspace()
    Check for white-space characters: 
	space, form-feed ('\f'), newline ('\n'), carriage return ('\r'), 
	horizontal tab ('\t'), and vertical tab ('\v'). 
*/
int	is_blank_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

// Parse config lines 
int	start_with_id(char *line, char *id)
{
	int	len;

	len = ft_strlen(id);
	if ((ft_strncmp(line, id, len) == 0) && line[len] == ' ')
		return (1);
	return (0);
}

int	is_config_line(char *line)
{
	if (start_with_id(line, "NO") || start_with_id(line, "SO")
		|| start_with_id(line, "WE") || start_with_id(line, "EA")
		|| start_with_id(line, "F") || start_with_id(line, "C"))
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	save_texture(int *cnt, char **dest, char *path)
{
	(*cnt)++;
	if (*cnt == 1)
		*dest = ft_strdup(path);
}

int	check_texture(char *id, char *path, t_map_info *map)
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
		return (printf("Invalid id: %s\n", id), 0);
	return (1);
}

void	free_split(char **array)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (array[cnt])
		cnt++;
	while (i < cnt)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	is_number_in_range(const char *str)
{
	int	i;
	int	acc;

	i = 0;
	acc = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (printf("It's not a number\n"), 0);
		acc = acc * 10 + (str[i] - '0');
		if (acc < 0 || acc > 255)
			return (printf("Color out of range\n"), 0);
		i++;
	}
	return (1);
}

int	check_commas(char *colors)
{
	int	i;
	int	comma_cnt;

	i = 0;
	comma_cnt = 0;
	while (colors[i])
	{
		if (colors[i] == ',')
			comma_cnt++;
		i++;
	}
	if (comma_cnt != 2)
		return (printf("Error: Colors only accept 2 commas\n"), 0);
	return (1);
}

int	save_rgb(char *id, char **color, t_map_info *map)
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
		return (printf("Only accept 3 numbers\n"), 0);
	return (1);
}

int	check_color(char *id, char *colors, t_map_info *map)
{
	char	**color;

	if (ft_strcmp(id, "F") == 0)
		(map->floor_cnt)++;
	else if (ft_strcmp(id, "C") == 0)
		(map->ceil_cnt)++;
	else
		return (printf("Invalid id: %s\n", id), 0);
	if (!check_commas(colors))
		return (0);
	color = ft_split(colors, ',');
	if (!color)
		return (printf("Error: Malloc failed\n"), 0);
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
		return (printf("Error: Malloc failed\n"), 0);
	n = 0;
	while (token[n])
		n++;
	if (n != 2)
		return (printf("Only accept 2 tokens\n"), free_split(token), 0);
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
		return (printf("Invalid id: %s\n", token[0]), free_split(token), 0);
	return (free_split(token), 1);
}

// Locate map start
int	is_map_char(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_map_char(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	contain_open_tile(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}

// Check if the top row contains any `0`, `N`, `S`, `E`, `W` -> fail
int	handle_config_mode(char *line, t_map_info *map, int i, int *in_map)
{
	if (is_blank_line(line))
		return (1);
	if (is_config_line(line))
	{
		if (!check_element(line, map))
			return (0);
		return (1);
	}
	if (is_map_line(line))
	{
		map->map_start = i;
		*in_map = 1;
		if (contain_open_tile(line))
			return (printf("Invalid top row: %s\n", line), 0);
		return (1);
	}
	return (printf("Invalid line: %s\n", line), 0);
}

int	split_config_and_map(t_map_info *map)
{
	int		i;
	int		in_map;
	char	*line;

	i = 0;
	in_map = 0;
	while (i < map->file_height)
	{
		line = map->lines[i];
		if (!in_map)
		{
			if (!handle_config_mode(line, map, i, &in_map))
				return (0);
		}
		else if (is_blank_line(line))
			return (printf("No blank line allowed inside the map\n"), 0);
		else if (!is_map_line(line))
			return (printf("Invalid map line\n"), 0);
		i++;
	}
	if (!in_map)
		return (printf("No map line\n"), 0);
	return (1);
}

// Step 4 - Check configuration identifiers count 
int	is_valid_element_count(t_map_info *map)
{
	if (map->no_cnt != 1)
		return (printf("Error: Invalid tex_NO count: %d\n", map->no_cnt), 0);
	if (map->so_cnt != 1)
		return (printf("Error: Invalid tex_SO count: %d\n", map->so_cnt), 0);
	if (map->we_cnt != 1)
		return (printf("Error: Invalid tex_WE count: %d\n", map->we_cnt), 0);
	if (map->ea_cnt != 1)
		return (printf("Error: Invalid tex_EA count: %d\n", map->ea_cnt), 0);
	if (map->floor_cnt != 1)
		return (printf("Error: Invalid floor count: %d\n", map->floor_cnt), 0);
	if (map->ceil_cnt != 1)
		return (printf("Error: Invalid ceil count: %d\n", map->ceil_cnt), 0);
	return (1);
}

// Step 5 - Collect map lines
// Check if the bottom row contains any `0`, `N`, `S`, `E`, `W` -> fail
int	store_map_lines(t_map_info *map)
{
	int	i;
	int	j;

	map->map_height = map->file_height - map->map_start;
	map->map_lines = malloc((map->map_height + 1) * sizeof(char *));
	if (!map->map_lines)
	{
		printf("Error: Malloc failed\n");
		return (0);
	}
	i = 0;
	j = map->map_start;
	while (j < map->file_height)
	{
		map->map_lines[i] = map->lines[j];
		i++;
		j++;
	}
	map->map_lines[i] = NULL;
	if (contain_open_tile(map->map_lines[map->map_height - 1]))
		return (printf("Invalid bottom row: %s\n"
				, map->map_lines[map->map_height - 1]), 0);
	return (1);
}

// Step 6 - Compute map dimensions
int	is_open_tile(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

// Check if the first/last column contains any `0`, `N`, `S`, `E`, `W` -> fail
int	compute_map_width(t_map_info *map)
{
	int	i;
	int	line_width;

	i = 0;
	while (i < map->map_height)
	{
		line_width = ft_strlen(map->map_lines[i]);
		if (is_open_tile(map->map_lines[i][0]))
		{
			printf("Invalid left column\n");
			return (0);
		}
		if (is_open_tile(map->map_lines[i][line_width - 1]))
		{
			printf("Invalid right column\n");
			return (0);
		}
		if (line_width > map->map_width)
			map->map_width = line_width;
		i++;
	}
	return (1);
}

// Step 7 - Normalize map
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

int	create_map(t_map_info *map)
{
	int	i;
	int	j;

	map->norm_map = malloc((map->map_height + 1) * sizeof(char *));
	if (!map->norm_map)
		return (printf("Error: Malloc failed\n"), 0);
	i = 0;
	while (i < map->map_height)
	{
		map->norm_map[i] = malloc(map->map_width + 1);
		if (!map->norm_map[i])
			return (ft_free_array(map->norm_map, i)
				, printf("Error: Malloc failed\n"), 0);
		j = 0;
		while (j < map->map_width)
		{
			map->norm_map[i][j] = ' ';
			j++;
		}
		map->norm_map[i][map->map_width] = '\0';
		i++;
	}
	map->norm_map[map->map_height] = NULL;
	return (1);
}

void	fill_map(t_map_info *map)
{
	int	i;
	int	j;
	int	line_width;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		line_width = ft_strlen(map->map_lines[i]);
		while (j < line_width)
		{
			(map->norm_map)[i][j] = (map->map_lines)[i][j];
			j++;
		}
		i++;
	}
}

// Step 8 - Player extraction
int	set_player(t_map_info *map, int i, int j, int *find_player)
{
	if (*find_player != 0)
		return (printf("Only accept one player\n"), 0);
	*find_player = 1;
	map->player_x = j + 0.5;
	map->player_y = i + 0.5;
	map->player_dir = map->norm_map[i][j];
	map->norm_map[i][j] = '0';
	return (1);
}

int	check_player(t_map_info *map)
{
	int	i;
	int	j;
	int	find_player;

	i = 0;
	find_player = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (ft_strchr("NSEW", map->norm_map[i][j]))
			{
				if (!set_player(map, i, j, &find_player))
					return (0);
			}
			j++;
		}
		i++;
	}
	if (find_player == 0)
		return (printf("No player\n"), 0);
	return (1);
}

// Step 9 - Map validation
int	check_neighbors(t_map_info *map, int x, int y)
{
	if (y > 0 && map->norm_map[y - 1][x] == ' ')
		return (0);
	if (y + 1 < map->map_height && map->norm_map[y + 1][x] == ' ')
		return (0);
	if (x > 0 && map->norm_map[y][x - 1] == ' ')
		return (0);
	if (x + 1 < map->map_width && map->norm_map[y][x + 1] == ' ')
		return (0);
	return (1);
}

int	check_map(t_map_info *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (map->norm_map[i][j] == '0')
			{
				if (!check_neighbors(map, j, i))
				{
					printf("Invalid map\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

// The camera plane is always perpendicular (90 degrees) to the direction vector
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
	else if (map->player_dir == 'E')
		set_math_vectors(map, 1.0, 0.0);
	else if (map->player_dir == 'W')
		set_math_vectors(map, -1.0, 0.0);
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
		return (printf("Error: Expected exactly one map path\n"), 1);
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
