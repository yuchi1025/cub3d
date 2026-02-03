/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:35:33 by yucchen           #+#    #+#             */
/*   Updated: 2025/07/11 13:32:37 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Locate character in string. Return a pointer to the first occurrence 
 			of the character c in the string s.
 *	@param s const char *
 *	@param c int
 *	@return A pointer to the matched character or 
 			NULL if the character is not found.
 			The terminating null byte is considered part of the string, 
			so that if c is specified as '\0', 
			these functions return a pointer to the terminator.
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*s = "Hello\n42";

	printf("Find H in Hello: %s vs %s\n", strchr(s, '\n'), ft_strchr(s, '\n'));
	printf("Find e in Hello: %s vs %s\n", strchr(s, 'e'), ft_strchr(s, 'e'));
	printf("Find l in Hello: %s vs %s\n", strchr(s, 'l'), ft_strchr(s, 'l'));
	printf("Find o in Hello: %s vs %s\n", strchr(s, 'o'), ft_strchr(s, 'o'));
	printf("Find h in Hello: %s vs %s\n", strchr(s, 'h'), ft_strchr(s, 'h'));
	printf("Find terminate char in Hello: %s vs %s\n", strchr(s, '\0'),
		ft_strchr(s, '\0'));
	return (0);
} */
