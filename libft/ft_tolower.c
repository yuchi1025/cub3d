/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:00:33 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/19 15:17:09 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Convert uppercase letters to lowercase.
 *	@param c int
 *	@return The converted letter, or c if the conversion was not possible.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/* #include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("Check d: %c vs %c\n", tolower('d'), ft_tolower('d'));
	printf("Check D -> d: %c vs %c\n", tolower('D'), ft_tolower('D'));
	printf("Check 1: %c vs %c\n", tolower('1'), ft_tolower('1'));
	return (0);
} */
