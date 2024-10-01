/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:55:58 by ego               #+#    #+#             */
/*   Updated: 2024/10/01 20:04:03 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)b;
	i = -1;
	while (++i < len)
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
	}
	return (NULL);
}
