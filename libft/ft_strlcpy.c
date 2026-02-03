/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:06:25 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/17 16:16:04 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Copy up to size - 1 characters from the NUL-terminated string src
			to dst, NUL-terminating the result.
			(As long as size is larger than 0)
			Note that a byte for the NUL should be included in size.
 *	@param dst char *
 *	@param src const char *
 *	@param size size_t
 *	@return The length of src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/* #include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	dst1[10];
	char	dst2[10];

	ft_strlcpy(dst1, "Hello!", 7);
	strlcpy(dst2, "Hello!", 7);
	printf("After: %s vs %s\n", dst1, dst2);
	printf("Length: %zu vs %zu\n", strlcpy(dst2, "Hello!", 7), ft_strlcpy(dst1,
			"Hello!", 7));
	return (0);
} */
