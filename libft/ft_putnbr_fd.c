/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:41:25 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/21 17:34:41 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Output the integer ’n’ to the specified file descriptor.
 *	@param n The integer to output.
 *	@param fd The file descriptor on which to write.
 *	@return None
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

/* int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-1, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-42, 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(42, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0, 2);
	ft_putchar_fd('\n', 2);
	return (0);
} */
