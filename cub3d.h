/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:03:05 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/17 14:32:12 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysymdef.h>

// TODO: Screen width and height
# define SCREEN_W 800
# define SCREEN_H 600
# define KEY_ESC 65307

typedef struct s_map_info
{
	int		file_height;
	char	**lines;
	int		no_cnt;
	int		so_cnt;
	int		we_cnt;
	int		ea_cnt;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_cnt;
	int		ceil_cnt;
	int		floor_color[3];
	int		ceil_color[3];
	int		map_start;
	int		map_height;
	char	**map_lines;
	int		map_width;
	char	**norm_map;
	float	player_x;
	float	player_y;
	char	player_dir;

	// MLX
	void	*mlx_ptr;
	void	*window_ptr;
	// Image buffer variables
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_map_info;

// file_check.c
int	is_valid_map_file(char *path);
int	check_file_height(const char *path, t_map_info *map_info, char **storage);
int	read_file(const char *path, t_map_info *map_info, char **storage);

#endif
