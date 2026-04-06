/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:25:09 by yucchen           #+#    #+#             */
/*   Updated: 2026/04/06 15:25:00 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		return (printf("Error\nColors only accept 2 commas\n"), 0);
	return (1);
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
			return (printf("Error\nIt's not a number\n"), 0);
		acc = acc * 10 + (str[i] - '0');
		if (acc < 0 || acc > 255)
			return (printf("Error\nColor out of range\n"), 0);
		i++;
	}
	return (1);
}

// The RGB Bitshift: rgb[0] = Red, rgb[1] = Green, rgb[2] = Blue
int	get_color(int rgb[3])
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}
