/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:48:12 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/22 16:57:03 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Delete and free the given node and all its successors,
			using the function ’del’ and free(3).
			Finally, set the pointer to the list to NULL.
 *	@param lst The address of a pointer to a node.
 *	@param del The address of the function used to delete the content
			   of the node.
 *	@return None
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

/* void	delete_content(void *content)
{
	free(content);
}

#include <stdio.h>

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	char	*str1;
	char	*str2;

	str1 = (char *)malloc(10 * sizeof(char));
	if (!str1)
		return (1);
	str1[0] = 'H';
	str1[1] = 'i';
	str1[2] = '\0';

	str2 = (char *)malloc(10 * sizeof(char));
	if (!str2)
		return (1);
	str2[0] = '4';
	str2[1] = '2';
	str2[2] = '\0';

	node1 = ft_lstnew(str1);
	node2 = ft_lstnew(str2);

	node1->next = node2;

	ft_lstclear(&node1, delete_content);
	if (node1 == NULL)
		printf("Linked list clear!\n");
	return (0);
} */
