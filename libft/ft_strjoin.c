/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:32:11 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/25 18:19:39 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_join(char const *s1, char const *s2, char *join)
{
	size_t	i;
	size_t	s2_i;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	s2_i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	while (s1[i] && i < s1_len)
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[s2_i] && i < s1_len + s2_len)
	{
		join[i] = s2[s2_i];
		i++;
		s2_i++;
	}
	join[i] = '\0';
}

/**
 *  @brief	Allocate memory (using malloc(3)) and return a new string,
			which is the result of concatenating ’s1’ and ’s2’.
 *	@param s1 The prefix string.
 *	@param s2 The suffix string.
 *	@return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_join(s1, s2, join);
	return (join);
}

/* #include <stdio.h>

int	main(void)
{
	printf("Hello + World: %s\n", ft_strjoin("Hello", "World"));
	printf(" + World: %s\n", ft_strjoin("", "World"));
	printf("Hello + : %s\n", ft_strjoin("Hello", ""));
	printf(" + : %s\n", ft_strjoin("", ""));
	return (0);
} */