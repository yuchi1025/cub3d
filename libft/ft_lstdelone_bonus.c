/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:25:41 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/22 16:56:33 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Take a node as parameter and free its content 
 			using the function ’del’.
 			Free the node itself but does NOT free the next node.
 *	@param lst The node to free.
 *	@param del The address of the function used to delete the content.
 *	@return None
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/* void	delete_content(void *content)
{
	free(content);
}

#include <stdio.h>

int	main(void)
{
	t_list	*node;
	char	*str;

	str = (char *)malloc(10 * sizeof(char));
	if (!str)
		return (1);
	str[0] = 'H';
	str[1] = 'i';
	str[2] = '\0';

	node = ft_lstnew(str);
	if (!node)
	{
		free(str);
		return (1);
	}
	
	printf("Before del: %s\n", (char *)node->content);
	ft_lstdelone(node, delete_content);
	return (0);
} */
