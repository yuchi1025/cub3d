/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:42:34 by yucchen           #+#    #+#             */
/*   Updated: 2025/07/10 19:09:53 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_trimmed_start(char const *s1, char const *set,
		size_t len)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = len;
	while (i < len)
	{
		if (!ft_strchr(set, s1[i]))
		{
			start = i;
			break ;
		}
		i++;
	}
	return (start);
}

static size_t	ft_find_trimmed_end(char const *s1, char const *set, size_t len)
{
	size_t	end;

	end = 0;
	while (len--)
	{
		if (!ft_strchr(set, s1[len]))
		{
			end = len;
			break ;
		}
	}
	return (end);
}

/**
 *  @brief	Allocate memory (using malloc(3)) and return a copy of ’s1’
			with characters from ’set’ removed from the beginning and the end.
 *	@param s1 The string to be trimmed.
 *	@param set The string containing the set of characters to be removed.
 *	@return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	len;
	size_t	start;
	size_t	end;
	size_t	new_len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	start = ft_find_trimmed_start(s1, set, len);
	end = ft_find_trimmed_end(s1, set, len);
	if (end < start)
		return (ft_strdup(""));
	else
		new_len = end - start + 1;
	trimmed = (char *)malloc((new_len + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, new_len + 1);
	return (trimmed);
}

/* #include <stdio.h>

int	main(void)
{
	//printf("%s\n", ft_strtrim("  hello world  ", " "));
	//printf("%s\n", ft_strtrim("---42--Piscine---", "-42"));
	//printf("%s\n", ft_strtrim("xxx", "x"));
	//printf("%s\n", ft_strtrim("OpenAI", "z"));
	//printf("%s\n", ft_strtrim("", "abc"));
	//printf("%s\n", ft_strtrim("  trim me  ", ""));
	char *ptr;
	ptr = ft_strtrim("", "123");
	printf("%s\n", ptr);
	free(ptr);
	ptr = ft_strtrim("", "");
	printf("%s\n", ptr);
	free(ptr);
	ptr = ft_strtrim("abcdab", "acb");
	printf("%s\n", ptr);
	free(ptr);
	return (0);
} */
