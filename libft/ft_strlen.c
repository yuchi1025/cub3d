/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:20:28 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/25 22:07:59 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Calculate the length of a string pointed to by s,
		excluding the terminating null byte ('\0').
 *	@param s const char*
 *	@return The length of s.
 */
size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

/* #include <stdio.h>

int	main(void)
{
	printf("Hello(5): %zu vs %zu\n", strlen("Hello"), ft_strlen("Hello"));
	printf("Welcome!(8): %zu vs %zu\n", strlen("Welcome!"),
		ft_strlen("Welcome!"));
	printf("(0): %zu vs %zu\n", strlen(""), ft_strlen(""));
	return (0);
} */
