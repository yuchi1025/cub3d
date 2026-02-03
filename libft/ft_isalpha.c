/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:04:18 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/13 12:07:57 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Check for an alphabetic character; equivalent to (isupper(c)
		|| islower(c)).
 *	@param c int
 *	@return Nonzero if the character c falls into the tested class,
		and zero if not.
 */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("a isalpha: %d vs %d\n", isalpha('a'), ft_isalpha('a'));
	printf("0 !isalpha: %d vs %d\n", isalpha('0'), ft_isalpha('0'));
	return (0);
} */
