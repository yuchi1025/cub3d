/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:17:24 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/22 16:53:12 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Allocate memory (using malloc(3)) and return a new node.
			The ’content’ member variable is initialized
			with the given parameter ’content’.
			The variable ’next’ is initialized to NULL.
 *	@param content The content to store in the new node.
 *	@return A pointer to the new node
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* #include <stdio.h>

int	main(void)
{
	char *str;
	t_list *node;

	str = "Hello";
	node = ft_lstnew((void *)str);
	if (node)
	{
		printf("Node content: %s\n", (char *)node->content);
		printf("Node next: %p\n", node->next);
	}
	else
		printf("Malloc fail\n");
	free(node);
	return (0);
} */
