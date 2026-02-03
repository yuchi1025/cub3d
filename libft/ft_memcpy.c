/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:35:08 by yucchen           #+#    #+#             */
/*   Updated: 2025/07/31 18:51:09 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Copy n bytes from memory area src to memory area dest.
 *	@param dest void *
 *	@param src const void *
 *	@param n size_t
 *	@return A pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	size_t	i;
	char	dest1[6];
	char	src1[6] = "Hi\0yo";
	char	dest2[6];
	char	src2[6] = "Hi\0yo";

	i = 0;
	printf("Before ft_memcpy: %s\n", dest1);
	ft_memcpy(dest1, src1, 6);
	printf("After ft_memcpy: %s\n", dest1);
	printf("Before memcpy: %s\n", dest2);
	memcpy(dest2, src2, 6);
	printf("After memcpy: %s\n", dest2);
	while (i < 6)
	{
		printf("%c vs %c\n", dest1[i], dest2[i]);
		printf("%d vs %d\n", dest1[i], dest2[i]);
		i++;
	}
	return (0);
} */
