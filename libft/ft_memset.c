/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:15:24 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/14 11:29:33 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* To traverse the void pointer and modify every byte individually
	without any undefined behavior, typecast it into a string,
	which is easy to traverse one byte at a time. */

/**
 *  @brief	Fill the first n bytes of the memory area pointed to by s
			with the constant byte c.
 *	@param s void *
 *	@param c int
 *	@param n size_t
 *	@return A pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[10] = "abcdefg";
	char	str2[10] = "abcdefg";

	printf("Before memset: %s\n", str1);
	memset(str1, '*', 4);
	printf("After memset: %s\n", str1);
	printf("Before ft_memset: %s\n", str2);
	ft_memset(str2, '*', 4);
	printf("After ft_memset: %s\n", str2);
} */
