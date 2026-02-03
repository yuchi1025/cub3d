/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:03:47 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/21 16:43:00 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Output the character ’c’ to the specified file descriptor.
 *	@param c The character to output.
 *	@param fd The file descriptor on which to write.
 *	@return None
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int	main(void)
{
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('a', 2);
	ft_putchar_fd('\n', 1);
	return (0);
} */