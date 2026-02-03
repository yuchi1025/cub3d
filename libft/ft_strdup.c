/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:41:15 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/20 20:33:15 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Duplicate a string. 
  			Memory for the new string is obtained with malloc(3), 
 			and can be freed with free(3).
 *	@param s const char *
 *	@return A pointer to the duplicated string. 
 			It returns NULL if insufficient memory was available, 
 			with errno set to indicate the cause of the error.
 */
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("Hello: %s vs %s\n", strdup("Hello"), ft_strdup("Hello"));
	printf("Empty: %s vs %s\n", strdup(""), ft_strdup(""));
	printf("1234567890: %s vs %s\n", strdup("1234567890"),
		ft_strdup("1234567890"));
	return (0);
} */