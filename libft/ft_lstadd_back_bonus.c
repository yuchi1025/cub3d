/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:48:37 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/22 16:55:52 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Add the node ’new’ at the end of the list.
 *	@param lst The address of a pointer to the first node of a list.
 *	@param new A pointer to the node to be added.
 *	@return None
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/* #include <stdio.h>

int	main(void)
{
	t_list	*node;
	t_list	*new_node;
	t_list	*tmp;

	node = ft_lstnew("hello");
	new_node = ft_lstnew("world");
	ft_lstadd_back(&node, new_node);

	tmp = node;
	while (tmp)
	{
		printf("Node content: %s\n", (char *)tmp->content);
		printf("Node next: %p\n", tmp->next);
		tmp = tmp->next;
	}
	return (0);
} */