/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:35:20 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/20 14:32:22 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Compare only the first (at most) n bytes of s1 and s2.
 			The comparison is done using unsigned characters.
 *	@param s1 const char *
 *	@param s2 const char *
 *	@param n size_t
 *	@return An integer indicating the result of the comparison, as follows:
			• 0, if the s1 and s2 are equal;
			• a negative value if s1 is less than s2;
		    • a positive value if s1 is greater than s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("ABC vs ABC: %d vs %d\n", strncmp("ABC", "ABC", 3), ft_strncmp("ABC",
			"ABC", 3));
	printf("ABC vs AB: %d vs %d\n", strncmp("ABC", "AB", 1), ft_strncmp("ABC",
			"AB", 1));
	printf("ABC vs ABZ: %d vs %d\n", strncmp("ABC", "ABZ", 3), ft_strncmp("ABC",
			"ABZ", 3));
	printf("ABC vs ABJ: %d vs %d\n", strncmp("ABC", "ABJ", 0), ft_strncmp("ABC",
			"ABJ", 0));
	printf("ABC vs A: %d vs %d\n", strncmp("ABC", "A", 2), ft_strncmp("ABC",
			"A", 2));
	printf("A vs ABC: %d vs %d\n", strncmp("A", "ABC", 1), ft_strncmp("A",
			"ABC", 1));
	printf("a vs A: %d vs %d\n", strncmp("a", "A", 1), ft_strncmp("a", "A", 1));
	printf("A vs a: %d vs %d\n", strncmp("A", "a", 2), ft_strncmp("A", "a", 2));
	return (0);
} */
