/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:17:51 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/21 17:14:45 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Output the string ’s’ to the specified file descriptor.
 *	@param s The string to output.
 *	@param fd The file descriptor on which to write.
 *	@return None
 */
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/* int	main(void)
{
	ft_putstr_fd("ABC", 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("abc", 2);
	ft_putchar_fd('\n', 1);
	return (0);
} */
