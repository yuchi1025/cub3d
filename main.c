/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:16:01 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/08 20:32:31 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3d.h"

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

int	check_height(const char *path, t_map_info *map_info, char **storage)
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
		(map_info->height)++;
		next_line = get_next_line(fd, storage);
	}
	close(fd);
	if (map_info->height == 0)
		return (printf("Error: Empty map\n"), 0);
	return (1);
}

void	read_map(const char *path, t_map_info *map_info, char **storage)
{
	int		fd;
	int		i;
	char	*next_line;
	int		len;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("open error");
		return ;
	}	
	map_info->map = (char **)malloc((map_info->height + 1) * sizeof(char *));
	if (!map_info->map)
	{
		printf("Error: Malloc failed\n");
		return ;
	}
	while (i < map_info->height)
	{
		next_line = get_next_line(fd, storage);
		len = ft_strlen(next_line);
		if (len > 0 && next_line[len - 1] == '\n')
			next_line[len - 1] = '\0';
		map_info->map[i] = next_line;
		i++;
	}
	map_info->map[i] = NULL;
	close(fd);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
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
	//int		fd;

	if (ft_strcmp(id, "NO") == 0)
		(map_info->tex_no)++;
	else if (ft_strcmp(id, "SO") == 0)
		(map_info->tex_so)++;
	else if (ft_strcmp(id, "WE") == 0)
		(map_info->tex_we)++;
	else if (ft_strcmp(id, "EA") == 0)
		(map_info->tex_ea)++;
	else
	{
		printf("Invalid id: %s\n", id);
			return (0);
	}
	printf("path: %s\n", path);
	/* fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("open error");
		return (0);
	}
	close(fd); */
	return (1);
}

int	is_number_in_range(const char *str)
{
	int	acc;
	int	i;

	acc = 0;
	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (printf("It's not a number\n"), 0);
		if (acc < 0 || acc > 255)
			return (printf("Color out of range\n"), 0);
		acc = acc * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

int	check_color(char *id, char *colors, t_map_info *map_info)
{
	char	**color;
	int 	n;

	if (ft_strcmp(id, "F") == 0)
		(map_info->floor)++;
	else if (ft_strcmp(id, "C") == 0)
		(map_info->ceil)++;
	else
	{
		printf("Invalid id: %s\n", id);
			return (0);
	}
	color = ft_split(colors, ',');
	n = 0;
	while (color[n])
	{
		if (!is_number_in_range(color[n]))
			return (0);
		n++;
	}
	if (n != 3)
	{
		printf("Only accept 3 numbers\n");
		return (0);
	}
	return (1);
}

int	check_element(char *s, t_map_info *map_info)
{
	char	**token;
	int		n;
	char	*id;

	token = ft_split(s, ' ');
	n = 0;
	while (token[n])
		n++;
	if (n != 2)
	{
		printf("Only accept 2 tokens\n");
		return (0);
	}
	id = token[0];
	if (ft_strlen(id) == 2)
	{
		if (!check_texture(id, token[1], map_info))
			return (0);
	}
	else if (ft_strlen(id) == 1)
	{
		if (!check_color(id, token[1], map_info))
			return (0);
	}
	else
	{
		printf("Invalid id: %s\n", id);
			return (0);
	}
	return (1);
}

int	is_valid_element_count(t_map_info *map_info)
{
	if (map_info->tex_no != 1)
		return (printf("Error: Invalid text_NO count: %d\n",
				map_info->tex_no), 0);
	if (map_info->tex_so != 1)
		return (printf("Error: Invalid text_SO count: %d\n",
				map_info->tex_so), 0);
	if (map_info->tex_we != 1)
		return (printf("Error: Invalid text_WE count: %d\n",
				map_info->tex_we), 0);
	if (map_info->tex_ea != 1)
		return (printf("Error: Invalid text_EA count: %d\n",
				map_info->tex_ea), 0);
	if (map_info->floor != 1)
		return (printf("Error: Invalid floor count: %d\n",
				map_info->floor), 0);
	if (map_info->ceil != 1)
		return (printf("Error: Invalid ceil count: %d\n",
				map_info->ceil), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map_info	map_info;
	char *storage;
	
	storage = NULL;
	if (argc == 2)
	{
		if (!is_valid_map_file(argv[1]))
			return (printf("Error: Map check failed\n"), 1);
		check_height(argv[1], &map_info, &storage);
		read_map(argv[1], &map_info, &storage);
		
		// for checking
		int i = 0;
		while (i < map_info.height)
		{
			if (ft_strlen(map_info.map[i]) > 0)
			{
				printf("map[%d]:%s\n", i, map_info.map[i]);
				if (!is_map_line(map_info.map[i]))
				{
					if (!check_element(map_info.map[i], &map_info))
						return (1);
				}
			}
			i++;
		}
		if (!is_valid_element_count(&map_info))
			return (1);
		return (0);
	}
	return (printf("Error: Expected exactly one map path\n"), 1);
}
