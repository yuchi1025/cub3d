/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:16:01 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/13 17:15:46 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3d.h"

// Step 1 - File validation
int	is_valid_map_file(char *path)
{
	char	*map;
	int		len;
	int		fd;

	if (!path || path[0] == '\0')
		return (printf("Error: Empty path\n"), 0);
	map = ft_strrchr(path, '/');
	if (map)
		map++;
	else
		map = path;
	len = ft_strlen(map);
	if (len < 5 || ft_strncmp(map + len - 4, ".cub", 4) != 0)
		return (printf("Error: Map should in format *.cub\n"), 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror("open error"), 0);
	close(fd);
	return (1);
}

// Step 2 - Read file into lines
int	check_file_height(const char *path, t_map_info *map_info, char **storage)
{
	int		fd;
	char	*next_line;

	ft_bzero(map_info, sizeof(*map_info));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror("open error"), 0);
	next_line = get_next_line(fd, storage);
	while (next_line)
	{
		free(next_line);
		(map_info->file_height)++;
		next_line = get_next_line(fd, storage);
	}
	close(fd);
	if (map_info->file_height == 0)
		return (printf("Error: Empty file\n"), 0);
	return (1);
}

void	read_file(const char *path, t_map_info *map_info, char **storage)
{
	int		i;
	int		fd;
	char	*next_line;
	int		len;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("open error");
		return ;
	}
	map_info->lines = (char **)malloc((map_info->file_height + 1) * sizeof(char *));
	if (!map_info->lines)
	{
		printf("Error: Malloc failed\n");
		return ;
	}
	next_line = get_next_line(fd, storage);
	while (next_line)
	{
		len = ft_strlen(next_line);
		if (len > 0 && next_line[len - 1] == '\n')
			next_line[len - 1] = '\0';
		map_info->lines[i] = next_line;
		next_line = get_next_line(fd, storage);
		i++;
	}
	map_info->lines[i] = NULL;
	close(fd);
}

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

int	check_texture(char *id, char *path, t_map_info *map_info)
{
	int	fd;

	if (ft_strcmp(id, "NO") == 0)
		(map_info->no_cnt)++;
	else if (ft_strcmp(id, "SO") == 0)
		(map_info->so_cnt)++;
	else if (ft_strcmp(id, "WE") == 0)
		(map_info->we_cnt)++;
	else if (ft_strcmp(id, "EA") == 0)
		(map_info->ea_cnt)++;
	else
	{
		printf("Invalid id: %s\n", id);
			return (0);
	}
	fd = open(path, O_RDONLY);
	//if (fd == -1)
	//{
	//	perror("open error");
	//	return (0);
	//}
	//close(fd);
	return (1);
}

void	free_split(char **array)
{
	int	cnt;
	int i;

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

int	check_color(char *id, char *colors, t_map_info *map_info)
{
	char	**color;
	int 	n;

	if (ft_strcmp(id, "F") == 0)
		(map_info->floor_cnt)++;
	else if (ft_strcmp(id, "C") == 0)
		(map_info->ceil_cnt)++;
	else
	{
		printf("Invalid id: %s\n", id);
			return (0);
	}
	color = ft_split(colors, ',');
	if (!color)
	{
		printf("Error: Malloc failed\n");
		return (0);
	}
	n = 0;
	while (color[n])
	{
		if (!is_number_in_range(color[n]))
		{
			free_split(color);
			return (0);
		}
		n++;
	}
	if (n != 3)
	{
		printf("Only accept 3 numbers\n");
		free_split(color);
		return (0);
	}
	free_split(color);
	return (1);
}

int	check_element(char *line, t_map_info *map_info)
{
	char	**token;
	int		n;
	char	*id;

	token = ft_split(line, ' ');
	if (!token)
	{
		printf("Error: Malloc failed\n");
		return (0);
	}
	n = 0;
	while (token[n])
		n++;
	if (n != 2)
	{
		printf("Only accept 2 tokens\n");
		free_split(token);
		return (0);
	}
	id = token[0];
	if (ft_strlen(id) == 2)
	{
		if (!check_texture(id, token[1], map_info))
		{
			free_split(token);
			return (0);
		}
	}
	else if (ft_strlen(id) == 1)
	{
		if (!check_color(id, token[1], map_info))
		{
			free_split(token);
			return (0);
		}
	}
	else
	{
		printf("Invalid id: %s\n", id);
		{
			free_split(token);
			return (0);
		}
	}
	free_split(token);
	return (1);
}

// Locate map start
int	contain_map_tile(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N'
				|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}

int	contain_tile_zero(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int	is_map_charset_only(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	split_config_and_map(t_map_info *map_info)
{
	int		i;
	char	*mode;
	char	*line;

	i = 0;
	mode = "config";
	while (i < map_info->file_height)
	{
		line = map_info->lines[i];
		if (ft_strcmp(mode, "config") == 0)
		{
			if (is_blank_line(line))
			{
				i++;
				continue;
			}
			else if (is_config_line(line))
			{
				if (!check_element(line, map_info))
					return (0);
			}
			else if (contain_map_tile(line))
			{
				map_info->map_start = i;
				mode = "map";
				// Check if the first row contains any `0` -> fail
				if (contain_tile_zero(line))
				{
					printf("Invalid top line: %s\n", line);
						return (0);
				}
				if (!is_map_charset_only(line))
				{
					printf("Invalid top line: %s\n", line);
						return (0);
				}
			}
			else
			{
				printf("Invalid config line: %s\n", line);
					return (0);
			}
		}
		else
		{
			if (is_blank_line(line))
			{
				printf("No blank line allowed inside the map\n");
					return (0);
			}
			else if (is_config_line(line))
			{
				printf("No config line allowed after the map begins\n");
					return (0);
			}
			else if (!is_map_charset_only(line))
			{
				printf("Invalid map line: %s\n", line);
					return (0);
			}
		}
		i++;
	}
	if (ft_strcmp(mode, "map") != 0)
	{
		printf("No map line\n");
			return (0);
	}
	return (1);
}

// Step 4 - Check configuration identifiers count 
int	is_valid_element_count(t_map_info *map_info)
{
	if (map_info->no_cnt != 1)
		return (printf("Error: Invalid tex_NO count: %d\n",
				map_info->no_cnt), 0);
	if (map_info->so_cnt != 1)
		return (printf("Error: Invalid tex_SO count: %d\n",
				map_info->so_cnt), 0);
	if (map_info->we_cnt != 1)
		return (printf("Error: Invalid tex_WE count: %d\n",
				map_info->we_cnt), 0);
	if (map_info->ea_cnt != 1)
		return (printf("Error: Invalid tex_EA count: %d\n",
				map_info->ea_cnt), 0);
	if (map_info->floor_cnt != 1)
		return (printf("Error: Invalid floor count: %d\n",
				map_info->floor_cnt), 0);
	if (map_info->ceil_cnt != 1)
		return (printf("Error: Invalid ceil count: %d\n",
				map_info->ceil_cnt), 0);
	return (1);
}

// Step 5 - Collect map lines
int	store_map_lines(t_map_info *map_info)
{
	int i;
	int j;
	
	map_info->map_height = map_info->file_height - map_info->map_start;
	map_info->map_lines = malloc((map_info->map_height + 1) * sizeof(char *));
	if (!map_info->map_lines)
	{
		printf("Error: Malloc failed\n");
		return (0);
	}
	i = 0;
	j = map_info->map_start;
	while (j < map_info->file_height)
	{
		map_info->map_lines[i] = map_info->lines[j];
		i++;
		j++;
	}
	map_info->map_lines[i] = NULL;
	// Check if the last row contains any `0` -> fail
	if (contain_tile_zero(map_info->map_lines[map_info->map_height - 1]))
	{
		printf("Invalid bottom line: %s\n", map_info->map_lines[map_info->map_height - 1]);
		return (0);
	}
	printf("map_height: %d\n", map_info->map_height);
	return (1);
}

// Step 6 - Compute map dimensions
int	compute_map_width(t_map_info *map_info)
{
	int	i;
	int	line_width;

	i = 0;
    while (i < map_info->map_height)
    {
		line_width = ft_strlen(map_info->map_lines[i]);
		printf("map_lines[%d]:%s(len: %d)\n", i, map_info->map_lines[i], line_width);
		// Check if the first column contains any `0` -> fail
		if (map_info->map_lines[i][0] == '0')
		{
			printf("Invalid left column\n");
			return (0);
		}
		// Check if the last column contains any `0` -> fail
		if (map_info->map_lines[i][line_width - 1] == '0')
		{
			printf("Invalid right column\n");
			return (0);
		}
		if (line_width > map_info->map_width)
			map_info->map_width = line_width;
    	i++;
    }
	printf("map width: %d\n", map_info->map_width);
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

void	create_map(t_map_info *map_info)
{
	int	i;
	int j;

	map_info->norm_map = malloc((map_info->map_height + 1) * sizeof(char *));
	if (!map_info->norm_map)
	{
		printf("Error: Malloc failed\n");
		return ;
	}
	i = 0;
	while (i < map_info->map_height)
	{
		map_info->norm_map[i] = malloc((map_info->map_width + 1) * sizeof(char));
		if (!map_info->norm_map[i])
		{
			ft_free_array(map_info->norm_map, i);
			printf("Error: Malloc failed\n");
			return ;
		}
		j = 0;
		while (j < map_info->map_width)
		{
			map_info->norm_map[i][j] = ' ';
			j++;
		}
		map_info->norm_map[i][map_info->map_width] = '\0';
		i++;
	}
	map_info->norm_map[map_info->map_height] = NULL;
}

void	fill_map(t_map_info *map_info)
{
	int	i;
	int j;
	int	line_width;

	i = 0;
	while (i < map_info->map_height)
    {
		j = 0;
		line_width = ft_strlen(map_info->map_lines[i]);
		while (j < line_width)
		{
			(map_info->norm_map)[i][j] = (map_info->map_lines)[i][j];
			j++;
		}
		//line_width = ft_strlen(map_info->norm_map[i]);
		//printf("norm_map[%d]:%s(len: %d)\n", i, map_info->norm_map[i], line_width);
    	i++;
    }
}

// Step 8 - Player extraction
int	check_player(t_map_info *map_info)
{
	int	i;
	int	j;
	int	find_player;

	i = 0;
	find_player = 0;
	while (i < map_info->map_height)
	{
		j = 0;
		while (j < map_info->map_width)
		{
			if (map_info->norm_map[i][j] == 'N' || map_info->norm_map[i][j] == 'S'
				|| map_info->norm_map[i][j] == 'E' || map_info->norm_map[i][j] == 'W')
			{
				if (find_player != 0)
				{
					printf("Only accept one player\n");
					return (0);
				}
				find_player = 1;
				// place player at tile center
				map_info->player_x = j + 0.5;
				map_info->player_y = i + 0.5;
				map_info->player_dir = map_info->norm_map[i][j];
				map_info->norm_map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (find_player == 0)
	{
		printf("No player\n");
		return (0);
	}
	return (1);
}

// Step 9 - Map validation
//int	check_map(t_map_info *map_info)
//{
//	return (1);
//}

int	main(int argc, char **argv)
{
	t_map_info	map_info;
	char *storage;
	
	storage = NULL;
	if (argc == 2)
	{
		if (!is_valid_map_file(argv[1]))
			return (printf("Error: Map check failed\n"), 1);
		if (!check_file_height(argv[1], &map_info, &storage))
			return (1);
		read_file(argv[1], &map_info, &storage);
		if (!split_config_and_map(&map_info))
			return (1);
		if (!is_valid_element_count(&map_info))
			return (1);
		if (!store_map_lines(&map_info))
			return (1);
		if (!compute_map_width(&map_info))
			return (1);
		create_map(&map_info);
		fill_map(&map_info);
		if (!check_player(&map_info))
			return (1);
		//if (!check_map(&map_info))
		//	return (1);
		return (0);
	}
	return (printf("Error: Expected exactly one map path\n"), 1);
}
