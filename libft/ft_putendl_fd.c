/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:31:36 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/21 17:19:51 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Output the string ’s’ to the specified file descriptor
			followed by a newline.
 *	@param s The string to output.
 *	@param fd The file descriptor on which to write.
 *	@return None
 */
void	ft_putendl_fd(char *s, int fd)
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
	ft_putchar_fd('\n', fd);
}

/* int	main(void)
{
	ft_putendl_fd("ABC", 1);
	ft_putendl_fd("abc", 2);
	return (0);
} */
