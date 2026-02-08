/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:03:05 by yucchen           #+#    #+#             */
/*   Updated: 2026/02/08 17:52:41 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map_info
{
	int		width;
	int		height;
	int		tex_no;
	int		tex_so;
	int		tex_we;
	int		tex_ea;
	int		floor;
	int		ceil;
//	int		player_x;
//	int		player_y;
//	int		player_count;
//	int		exit_x;
//	int		exit_y;
//	int		exit_count;
//	int		collectible_count;
//	int		collected;
//	char	*last_line;
	char	**map;
}			t_map_info;

#endif
