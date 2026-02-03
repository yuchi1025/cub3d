/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:21:29 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/20 19:06:34 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Erase the data in the n bytes of the memory starting at the location
			pointed to by s, by writing zeros (bytes containing '\0')
			to that area.
 *	@param s void *
 *	@param n size_t
 *	@return None
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* #include <string.h>
#include <stdio.h>

int	main(void)
{
	char	str1[8] = "Hello";
	char	str2[8] = "Hello";
	int	i;

	i = 0;

	printf("Before ft_bzero: %s\n", str1);
	ft_bzero(str1, 3);
	printf("After ft_bzero: %s\n", str1);
	printf("Before bzero: %s\n", str2);
	bzero(str2, 3);
	printf("After bzero: %s\n", str2);
	while (i < 8)
	{
		printf("%c vs %c\n", str1[i], str2[i]);
		printf("%d  vs %d\n", str1[i], str2[i]);
		i++;
	}
	return (0);
} */
