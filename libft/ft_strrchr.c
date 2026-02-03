/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:43:50 by yucchen           #+#    #+#             */
/*   Updated: 2025/07/12 13:59:18 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Locate character in string. Return a pointer to the last occurrence 
 			of the character c in the string s.
 *	@param s const char *
 *	@param c int
 *	@return A pointer to the matched character or 
 			NULL if the character is not found.
 			The terminating null byte is considered part of the string, 
			so that if c is specified as '\0', 
			these functions return a pointer to the terminator.
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (s[len] == (char)c)
		return ((char *)(s + len));
	if (len)
	{
		while (len--)
		{
			if (s[len] == (char)c)
				return ((char *)(s + len));
		}
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*s = "Hello";

	printf("Find H in Hello: %s vs %s\n", strrchr(s, 'H'), ft_strrchr(s, 'H'));
	printf("Find e in Hello: %s vs %s\n", strrchr(s, 'e'), ft_strrchr(s, 'e'));
	printf("Find l in Hello: %s vs %s\n", strrchr(s, 'l'), ft_strrchr(s, 'l'));
	printf("Find h in Hello: %s vs %s\n", strrchr(s, 'h'), ft_strrchr(s, 'h'));
	printf("Find terminate char in Hello: %s vs %s\n", strrchr(s, '\0'),
		ft_strrchr(s, '\0'));
	return (0);
} */
