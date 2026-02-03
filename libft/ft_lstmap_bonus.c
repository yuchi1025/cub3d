/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:40:37 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/24 21:26:02 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Iterate through the list ’lst’, apply the function ’f’ 
 			to each node’s content, and create a new list 
			resulting of the successive applications of the function ’f’. 
			The ’del’ function is used to delete the content of a node if needed.
 *	@param lst The beginning of the list.
 *	@param f The address of the function applied to each node’s content.
 *	@param del The address of the function used to delete a node’s content 
 			   if needed.
 *	@return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/* void	*to_upper(void *content)
{
	char	*str;
	char	*new_str;
	int	i;

	str = (char *)content;
	i = 0;

	new_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			new_str[i] = str[i] - 32;
		else
			new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	delete_content(void *content)
{
	free(content);
}

#include <stdio.h>

int	main(void)
{
	t_list *origin;
	t_list *mapped;
	t_list *tmp;

	origin = NULL;
	mapped = NULL;
	ft_lstadd_back(&origin, ft_lstnew("hello"));
	ft_lstadd_back(&origin, ft_lstnew("World"));
	ft_lstadd_back(&origin, ft_lstnew("42"));

	mapped = ft_lstmap(origin, to_upper, delete_content);

	printf("Origin:\n");
	tmp = origin;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	printf("Mapped:\n");
	tmp = mapped;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	ft_lstclear(&origin, NULL);
	ft_lstclear(&mapped, delete_content);

	return (0);
} */
