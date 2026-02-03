/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:12:02 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/13 12:08:59 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Check for any printable character including space.
 *	@param c int
 *	@return Nonzero if the character c falls into the tested class,
		and zero if not.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf(" isprint: %d vs %d\n", isprint(' '), ft_isprint(' '));
	printf("128 !isprint: %d vs %d\n", isprint(128), ft_isprint(128));
	return (0);
} */
