/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:37:18 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/21 16:36:05 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Apply the function ’f’ to each character of the string
			passed as argument, passing its index as the first argument.
			Each character is passed by address to ’f’
			so it can be modified if necessary.
 *	@param s The string to iterate over.
 *	@param f The function to apply to each character.
 *	@return None
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	len;
	size_t	i;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, s + i);
		i++;
	}
}

/* void	to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

#include <stdio.h>

int	main(void)
{
	char str[] = "hello";

	printf("Before: %s\n", str);
	ft_striteri(str, to_upper);
	printf("After: %s\n", str);
	return (0);
} */