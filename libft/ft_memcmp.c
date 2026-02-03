/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:38:23 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/22 22:17:17 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Compare the first n bytes (each interpreted as unsigned char) 
 			of the memory areas s1 and s2.
 *	@param s1 const void *
 *	@param s2 const void *
 *	@param n size_t
 *	@return An integer less than, equal to, or greater than zero if the
       		first n bytes of s1 is found, respectively, to be less than, 
			to match, or be greater than the first n bytes of s2.
	   		For a nonzero return value, the sign is determined by the sign 
			of the difference between the first pair of bytes 
			(interpreted as unsigned char) that differ in s1 and s2.
			If n is zero, the return value is zero.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	i = 0;
	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("ABC vs ABC(0): %d vs %d\n", memcmp("ABC", "ABC", 0),
		ft_memcmp("ABC", "ABC", 0));
	printf("ABC vs ABZ(3): %d vs %d\n", memcmp("ABC", "ABZ", 3),
		ft_memcmp("ABC", "ABZ", 3));
	printf("ABC vs ABC(3): %d vs %d\n", memcmp("ABC", "ABC", 3),
		ft_memcmp("ABC", "ABC", 3));
	printf("BC vs ABC(2): %d vs %d\n", memcmp("BC", "ABC", 2), 
		ft_memcmp("BC",	"ABC", 2));
	return (0);
} */
