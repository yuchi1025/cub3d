/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:19:08 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/25 22:05:21 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Copy n bytes from memory area src to memory area dest.
			The memory areas may overlap.
 *	@param dest void *
 *	@param src const void *
 *	@param n size_t
 *	@return A pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (src_ptr < dest_ptr)
	{
		while (n--)
			dest_ptr[n] = src_ptr[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	char	src1[] = "abcdef";
	char	src2[] = "abcdef";

	printf("Before: %s vs %s\n", src1, src2);
	// test overlap
	ft_memmove(src1 + 2, src1, 3); // move "abc" after index 2
	memmove(src2 + 2, src2, 3);
	printf("After: %s vs %s\n", src1, src2);
	return (0);
} */

/*
1. src < dest && overlap: backwards
src
[][][][]
dest
	[][][][]
2. src < dest && no_overlap: ft_memcpy/backwards
src
[][][][]
dest
		[][][][]
3. src = dest: ft_memcpy/backwards
src
[][][][]
dest
[][][][]
4. src > dest && overlap: ft_memcpy
src
	[][][][]
dest
[][][][]
5. src > dest && no_overlap: ft_memcpy/backwards
src
		[][][][]
dest
[][][][]
*/
