/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:13:17 by yucchen           #+#    #+#             */
/*   Updated: 2025/07/11 13:59:49 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Allocate memory (using malloc(3)) and return a substring 
 * 			from the string ’s’. The substring starts at index ’start’
 * 			and has a maximum length of ’len’.
 *	@param s The original string from which to create the substring.
 *	@param start The starting index of the substring within ’s’.
 *	@param len The maximum length of the substring.
 *	@return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	else if (start + len <= s_len)
		sub = (char *)malloc((len + 1) * sizeof(char));
	else
		sub = (char *)malloc((s_len - start + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/* #include <stdio.h>

int	main(void)
{
	printf("Hello(2,0): %s\n", ft_substr("Hello", 2, 0));
	printf("Hello(2,3): %s\n", ft_substr("Hello", 2, 3));
	printf("Hello(2,5): %s\n", ft_substr("Hello", 2, 5));
	printf("Hi(5,3): %s\n", ft_substr("Hi", 5, 3));
	return (0);
} */
