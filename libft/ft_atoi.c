/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:26:14 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/20 18:03:02 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Convert a string pointed to by nptr to an integer.
			The string may begin with an arbitrary amount of white space 
			(isspace(3)) followed by a single optional '+' or '-' sign.
			isspace()
              Check for white-space characters: 
			  space, form-feed ('\f'), newline ('\n'), carriage return ('\r'), 
			  horizontal tab ('\t'), and vertical tab ('\v').
 *	@param nptr const char *
 *	@return The converted value or 0 on error.
 */
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' '))
		i++;
	if (nptr[i] && (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}

/* #include <stdio.h>

int	main(void)
{
	printf("   42: %d vs %d\n", atoi("   42"), ft_atoi("   42"));
	printf("   -42: %d vs %d\n", atoi("   -42"), ft_atoi("   -42"));
	printf("   2147483648: %d vs %d\n", atoi("   2147483648"),
		ft_atoi("   2147483648"));
	printf("   -2147483648: %d vs %d\n", atoi("   -2147483648"), 
	ft_atoi("   -2147483648"));
	printf("   +-42: %d vs %d\n", atoi("   +-42"), ft_atoi("   +-42"));
	return (0);
} */
