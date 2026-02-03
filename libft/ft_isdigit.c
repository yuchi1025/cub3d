/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:24:53 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/13 12:08:37 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Check for a digit (0 through 9).
 *	@param c int
 *	@return Nonzero if the character c falls into the tested class,
		and zero if not.
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("a !isdigit: %d vs %d\n", isdigit('a'), ft_isdigit('a'));
	printf("0 isdigit: %d vs %d\n", isdigit('0'), ft_isdigit('0'));
	return (0);
} */
