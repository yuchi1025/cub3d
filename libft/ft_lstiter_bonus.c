/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:24:25 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/22 16:57:22 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Iterate through the list ’lst’ and apply the function ’f’ 
 			to the content of each node.
 *	@param lst The beginning of the list.
 *	@param f The address of the function to apply to each node’s content.
 *	@return None
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* #include <stdio.h>

void	print_content(void *content)
{
	printf("Content: %s\n", (char *)content);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew("Hello");
	node2 = ft_lstnew("World");
	node3 = ft_lstnew("42");

	node1->next = node2;
	node2->next = node3;

	ft_lstiter(node1, print_content);
	return (0);
} */