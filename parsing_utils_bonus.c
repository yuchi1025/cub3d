/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:03:21 by yucchen           #+#    #+#             */
/*   Updated: 2026/04/21 21:22:13 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

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

static int	start_with_id(char *line, char *id)
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
