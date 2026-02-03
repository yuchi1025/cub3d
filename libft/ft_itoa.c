/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:54:25 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/25 18:14:15 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt_len(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_put_pos_nbr(char *str, long n, int *j)
{
	if (n >= 10)
		ft_put_pos_nbr(str, n / 10, j);
	str[*j] = (n % 10) + '0';
	*j = *j + 1;
}

/**
 *  @brief	Allocate memory (using malloc(3)) and return a string
			representing the integer received as an argument.
			Negative numbers must be handled.
 *	@param n The integer to convert.
 *	@return The string representing the integer. NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;
	int		len;

	nb = n;
	i = 0;
	if (nb < 0)
		nb = -nb;
	len = ft_cnt_len(nb);
	if (n < 0)
		str = (char *)malloc((1 + len + 1) * sizeof(char));
	else
		str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		i = 1;
	}
	ft_put_pos_nbr(str, nb, &i);
	str[i] = '\0';
	return (str);
}

/* #include <stdio.h>

int	main(void)
{
	printf("0: %s\n", ft_itoa(0));
	printf("42: %s\n", ft_itoa(42));
	printf("-42: %s\n", ft_itoa(-42));
	printf("-2147483648: %s\n", ft_itoa(-2147483648));
	return (0);
} */
