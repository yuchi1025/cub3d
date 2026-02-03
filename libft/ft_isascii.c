/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:42:02 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/13 12:09:01 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Check whether c is a 7-bit unsigned char value that fits
		into the ASCII character set.
 *	@param c int
 *	@return Nonzero if the character c falls into the tested class,
		and zero if not.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf(" isascii: %d vs %d\n", isascii(' '), ft_isascii(' '));
	printf("128 !isascii: %d vs %d\n", isascii(128), ft_isascii(128));
	return (0);
} */
