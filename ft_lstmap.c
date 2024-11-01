/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:08:01 by ego               #+#    #+#             */
/*   Updated: 2024/10/13 14:34:26 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmap_free(t_list *lst, void (*del)(void *))
{
	t_list	*node;

	while (lst)
	{
		node = lst->next;
		del(lst->content);
		free(lst);
		lst = node;
	}
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	if (!lst)
		return (NULL);
	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	node = head;
	while (lst)
	{
		node->content = f(lst->content);
		lst = lst->next;
		if (lst)
		{
			node->next = (t_list *)malloc(sizeof(t_list));
			if (!(node->next))
				return (ft_lstmap_free(head, del));
			node = node->next;
		}
	}
	node->next = NULL;
	return (head);
}
