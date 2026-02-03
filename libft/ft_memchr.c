/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:35:42 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/20 15:28:26 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Scan the initial n bytes of the memory area pointed to by s 
 			for the first instance of c.
	   		Both c and the bytes of the memory area pointed to by s
			are interpreted as unsigned char.
 *	@param s const void *
 *	@param c int
 *	@param n size_t
 *	@return A pointer to the matching byte or NULL 
			if the character does not occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	const void	*s = "Hello";

	printf("Find H in Hello(3): %s vs %s\n", (char *)memchr(s, 'H', 3),
		(char *)ft_memchr(s, 'H', 3));
	printf("Find l in Hello(4): %s vs %s\n", (char *)memchr(s, 'l', 4),
		(char *)ft_memchr(s, 'l', 4));
	printf("Find H in Hello(0): %s vs %s\n", (char *)memchr(s, 'H', 0),
		(char *)ft_memchr(s, 'H', 0));
	printf("Find o in Hello(3): %s vs %s\n", (char *)memchr(s, 'o', 3),
		(char *)ft_memchr(s, 'o', 3));
	printf("Find a in Hello(4): %s vs %s\n", (char *)memchr(s, 'a', 4),
		(char *)ft_memchr(s, 'a', 4));
	printf("Find '\\0' in Hello(6): %p vs %p\n", memchr(s, '\0', 6),
		ft_memchr(s, '\0', 6));
	return (0);
} */
