/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:15:19 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/16 10:25:12 by yucchen          ###   ########.fr       */
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

int	read_file(const char *path, t_map_info *map_info, char **storage)
{
	int		i;
	int		fd;
	char	*next_line;
	int		len;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror("open error"), 0);
	map_info->lines = malloc((map_info->file_height + 1) * sizeof(char *));
	if (!map_info->lines)
		return (printf("Error: Malloc failed\n"), 0);
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
	return (1);
}
