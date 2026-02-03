/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:22:24 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/21 16:01:48 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Apply the function f to each character of the string s,
			passing its index as the first argument 
			and the character itself as the second.
			A new string is created (using malloc(3)) to store the results
			from the successive applications of f.
 *	@param s The string to iterate over.
 *	@param f The function to apply to each character.
 *	@return The string created from the successive applications of ’f’.
			Return NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

#include <stdio.h>

int	main(void)
{
	printf("hello: %s\n", ft_strmapi("hello", to_upper));
	return (0);
} */
