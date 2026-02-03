/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:11:27 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/18 11:42:12 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Append the NUL-terminated string src to the end of dst.
			It will append at most size - strlen(dst) - 1 bytes,
			NUL-terminating the result.
			Note that a byte for the NUL should be included in size.
 *	@param dst char *
 *	@param src const char *
 *	@param size size_t
 *	@return The total length of the string they tried to create.
			1. The initial length of dst plus the length of src.
			2. If traverses size characters without finding a NUL,
			the length of the string is considered to be size
			and the destination string will not be NUL-terminated
			(since there was no space for the NUL).
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i < size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/* #include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	dst1[20] = "Hello";
	char	dst2[20] = "Hello";
	char	dst3[3] = "Hi";
	char	dst4[3] = "Hi";
	char	dst5[4] = "Hey";
	char	dst6[4] = "Hey";
	const char	*src = "42";

	printf("Check ft_strlcat: %s (len: %zu)\n", dst1, ft_strlcat(dst1, src,
			sizeof(dst1)));
	printf("Check strlcat: %s (len: %zu)\n", dst2, strlcat(dst2, src,
			sizeof(dst2)));
	printf("Check ft_strlcat(Truncation): %s (len: %zu)\n", dst3,
		ft_strlcat(dst3, src, sizeof(dst3)));
	printf("Check strlcat(Truncation): %s (len: %zu)\n", dst4, strlcat(dst4,
			src, sizeof(dst4)));
	printf("Check ft_strlcat(size < dst_len): %s (len: %zu)\n", dst5,
		ft_strlcat(dst5, src, 3));
	printf("Check strlcat(size < dst_len): %s (len: %zu)\n", dst6, strlcat(dst6,
			src, 3));
	return (0);
} */
