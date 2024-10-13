/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:19:34 by ego               #+#    #+#             */
/*   Updated: 2024/10/13 14:34:36 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				diff;
	size_t			i;

	s1 = (unsigned char *)b1;
	s2 = (unsigned char *)b2;
	i = 0;
	while (i < n)
	{
		diff = (int)s1[i] - (int)s2[i];
		if (diff)
			return ((int)diff);
		i++;
	}
	return (0);
}
