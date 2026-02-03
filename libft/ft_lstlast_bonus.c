/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:17:03 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/22 16:55:25 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Return the last node of the list.
 *	@param lst The beginning of the list.
 *	@return Last node of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

/* #include <stdio.h>

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew("Hello");
	node2 = ft_lstnew("World");
	node3 = ft_lstnew("42");

	ft_lstadd_front(&node3, node2);
	ft_lstadd_front(&node2, node1);

	printf("Hello->World->42: %s\n", (char *)ft_lstlast(node1)->content);
	return (0);
} */