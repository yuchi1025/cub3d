/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:52:13 by yucchen           #+#    #+#             */
/*   Updated: 2025/07/10 19:01:05 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar('-');
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	ft_putchar((unsigned char)((n % 10) + '0'));
	count++;
	return (count);
}

int	ft_putunsignednbr(unsigned int u)
{
	int	count;

	count = 0;
	if (u >= 10)
		count += ft_putunsignednbr(u / 10);
	ft_putchar((unsigned char)((u % 10) + '0'));
	count++;
	return (count);
}

int	ft_puthexalower(unsigned int x)
{
	int		count;
	char	*hexalowerbase;

	count = 0;
	hexalowerbase = "0123456789abcdef";
	if (x >= 16)
		count += ft_puthexalower(x / 16);
	ft_putchar((unsigned char)hexalowerbase[x % 16]);
	count++;
	return (count);
}

int	ft_puthexaupper(unsigned int X)
{
	int		count;
	char	*hexaupperbase;

	count = 0;
	hexaupperbase = "0123456789ABCDEF";
	if (X >= 16)
		count += ft_puthexaupper(X / 16);
	ft_putchar((unsigned char)hexaupperbase[X % 16]);
	count++;
	return (count);
}

int	ft_putptr(uintptr_t ptr)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (ptr >= 16)
		count += ft_putptr(ptr / 16);
	ft_putchar((unsigned char)hexa[ptr % 16]);
	count++;
	return (count);
}
