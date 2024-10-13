/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:55:03 by ego               #+#    #+#             */
/*   Updated: 2024/10/13 14:34:22 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;
	t_list	*temp;

	l = *lst;
	while (l)
	{
		temp = l->next;
		ft_lstdelone(l, del);
		l = temp;
	}
	*lst = NULL;
}
