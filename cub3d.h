/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:03:05 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/12 18:51:47 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map_info
{
	int		file_height;
	char	**lines;
	int		no_cnt;
    int		so_cnt;
    int		we_cnt;
    int		ea_cnt;
	int		floor_cnt;
	int		ceil_cnt;
	int		map_start;
	int		map_height;
	char	**map_lines;
	int		map_width;
	char	**norm_map;
	int		player_x;
	int		player_y;
	int		player_dir;
}			t_map_info;

#endif
