/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:03:05 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/18 14:53:16 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysymdef.h>
# include <math.h>

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

	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

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

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	// Current square of the map the ray is in
	int		map_x;
	int		map_y;
	// Length of ray from one X/Y-side to next X/Y-side
	double	delta_dist_x;
	double	delta_dist_y;
	// Length of ray from current pos to next X/Y-side
	double	side_dist_x;
	double	side_dist_y;
	// Distance to the wall to prevent fish-eye
	double	perp_wall_dist;
	// Direction to step in X/Y (+1 or -1)
	int		step_x;
	int		step_y;
	// Was a wall hit
	int		hit;
	// Was a NS(0) or EW(1) wall hit
	int		side;
	// Height of the line to draw on screen
	int		line_height;
	// Lowest pixel to fill in current stripe
	int		draw_start;
	// Highest pixel to fill in current stripe
	int		draw_end;
}			t_ray;

// file_check.c
int		is_valid_map_file(char *path);
int		check_file_height(const char *path, t_map_info *map, char **storage);
int		read_file(const char *path, t_map_info *map, char **storage);

// TODO: Need to check
// init_mlx.c
int		init_window(t_map_info *map);
int		init_image(t_map_info *map);
int		ft_close(t_map_info *map);
int		ft_keypress(int keycode, t_map_info *map);
void	ft_mlx_pixel_put(t_map_info *map, int x, int y, int color);
int		get_color(int rgb[3]);
void	render_background(t_map_info *map);
int		render_frame(t_map_info *map);
void	start_game(t_map_info *map);

// raycaster.c
void	cast_rays(t_map_info *map);

// TODO: Need to check
// main.c
void	free_map_info(t_map_info *map);

#endif
