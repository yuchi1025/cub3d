/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:39:31 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/22 16:54:02 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Add the node ’new’ at the beginning of the list.
 *	@param lst The address of a pointer to the first node of a list.
 *	@param new A pointer to the node to be added.
 *	@return None
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* #include <stdio.h>

int	main(void)
{
	t_list	*node;
	t_list	*new_node;
	t_list	*tmp;

	node = ft_lstnew("world");
	new_node = ft_lstnew("hello");
	ft_lstadd_front(&node, new_node);

	tmp = node;
	while (tmp)
	{
		printf("Node content: %s\n", (char *)tmp->content);
		printf("Node next: %p\n", tmp->next);
		tmp = tmp->next;
	}
	return (0);
} */