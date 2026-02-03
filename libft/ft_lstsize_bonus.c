/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:54:10 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/22 16:54:25 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Count the number of nodes in the list.
 *	@param lst The beginning of the list.
 *	@return The length of the list.
 */
int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
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

	printf("Hello->World->42(3): %d\n", ft_lstsize(node1));
	return (0);
} */