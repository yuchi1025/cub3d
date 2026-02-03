/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:52:03 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/13 12:07:27 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Check for an alphanumeric character; equivalent to (isalpha(c)
		|| isdigit(c)).
 *	@param c int
 *	@return Nonzero if the character c falls into the tested class,
		and zero if not.
 */
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'))
		return (1);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("a isalnum: %d vs %d\n", isalnum('a'), ft_isalnum('a'));
	printf("0 isalnum: %d vs %d\n", isalnum('0'), ft_isalnum('0'));
	printf(" !isalnum: %d vs %d\n", isalnum(' '), ft_isalnum(' '));
	return (0);
} */
