/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:42:26 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/19 15:13:03 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Convert lowercase letters to uppercase.
 *	@param c int
 *	@return The converted letter, or c if the conversion was not possible.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/* #include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("Check d -> D: %c vs %c\n", toupper('d'), ft_toupper('d'));
	printf("Check D: %c vs %c\n", toupper('D'), ft_toupper('D'));
	printf("Check 1: %c vs %c\n", toupper('1'), ft_toupper('1'));
	return (0);
} */
