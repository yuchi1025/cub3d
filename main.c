/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:16:01 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/04 16:48:37 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3d.h"

int	is_valid_map_file(char *path)
{
	char *map;
	int	len;
	int fd;

	if (!path || path[0] == '\0')
		return (ft_printf("Error: Empty path\n"), 0);
	map = ft_strrchr(path, '/');
	if (map)
		map++;
	else
		map = path;
	len = ft_strlen(map);
	if (len < 5 || ft_strncmp(map + len - 4, ".cub", 4) != 0)
		return (ft_printf("Error: Map should in format *.cub\n"), 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error: Cannot open map file\n"), 0);
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!is_valid_map_file(argv[1]))
			return (ft_printf("Error: Map check failed\n"), 1);
		return (0);
	}
	(void)argv;
	return (ft_printf("Error: Expected exactly one map path\n"), 1);
}
