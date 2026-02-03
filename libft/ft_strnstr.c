/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:38:43 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/20 16:48:35 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Locate a substring in a string.
 			Locate the first occurrence of the null-terminated string little 
			in the string big, where not more than len characters are searched.  
			Characters that appear after a ‘\0’ character are not searched.
 *	@param big const char *
 *	@param little const char *
 *	@param len size_t
 *	@return If little is an empty string, big is returned; 
 			if little occurs nowhere in big, NULL is returned; 
			otherwise a pointer to the first character of the first occurrence 
			of little is returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	big_index;

	little_len = ft_strlen(little);
	big_index = 0;
	if (!little_len)
		return ((char *)big);
	if (len < little_len)
		return (NULL);
	while ((big_index < (len - little_len + 1)) && big[big_index])
	{
		if (!ft_strncmp(big + big_index, little, little_len))
			return ((char *)(big + big_index));
		big_index++;
	}
	return (NULL);
}

/* #include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	printf("Find Bar in Foo Bar Baz(4): %s vs %s\n", strnstr("Foo Bar Baz",
			"Bar", 4),
		ft_strnstr("Foo Bar Baz", "Bar", 4));
	printf("Find nothing in Hello(3): %s vs %s\n", strnstr("Hello", "", 3),
		ft_strnstr("Hello", "", 3));
	printf("Find He in Hello(3): %s vs %s\n", strnstr("Hello", "He", 3),
		ft_strnstr("Hello", "He", 3));
	printf("Find He in AHello(3): %s vs %s\n", strnstr("AHello", "He", 3),
		ft_strnstr("AHello", "He", 3));
	printf("Find He in AHello(1): %s vs %s\n", strnstr("AHello", "He", 1),
		ft_strnstr("AHello", "He", 1));
	printf("Find HI in Hello(3): %s vs %s\n", strnstr("Hello", "HI", 3),
		ft_strnstr("Hello", "HI", 3));
	return (0);
} */
