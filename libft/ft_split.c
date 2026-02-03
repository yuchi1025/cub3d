/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:25:38 by yucchen           #+#    #+#             */
/*   Updated: 2025/07/12 13:46:11 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt_word(char const *s, char c)
{
	size_t	i;
	size_t	word_len;
	size_t	cnt;

	i = 0;
	word_len = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word_len++;
			if (word_len == 1)
				cnt++;
		}
		else
			word_len = 0;
		i++;
	}
	return (cnt);
}

static void	ft_free_array(char **array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	ft_cpy_word(char const *s, char c, char **array)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		array[j] = (char *)malloc((i - start + 1) * sizeof(char));
		if (!array[j])
		{
			ft_free_array(array, j);
			return (0);
		}
		ft_strlcpy(array[j], s + start, i - start + 1);
		j++;
	}
	return (1);
}

/**
 *  @brief	Allocate memory (using malloc(3)) and return an array of strings
			obtained by splitting ’s’ using the character ’c’ as a delimiter.
			The array must end with a NULL pointer.
 *	@param s The string to be split.
 *	@param c The delimiter character.
 *	@return The array of new strings resulting from the split.
			NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	size_t	cnt;
	char	**array;

	cnt = ft_cnt_word(s, c);
	array = (char **)malloc((cnt + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (!ft_cpy_word(s, c, array))
		return (NULL);
	array[cnt] = NULL;
	return (array);
}

/* #include <stdio.h>

int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("a b c", ' ');
	//result = ft_split("  hello   world   42  ", ' ');
	//result = ft_split("", ' ');
	//result = ft_split("hello", ' ');
	//result = ft_split(" ", ' ');
	if (!result)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	i = 0;
	while (result[i])
	{
		printf("result[%d] = %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
} */
