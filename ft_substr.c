/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:18:45 by ego               #+#    #+#             */
/*   Updated: 2024/10/02 00:32:31 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (start >= ft_strlen(s))
		return ("");
	i = (size_t)start;
	while (s[i] && (i - (size_t)start) < len)
		i++;
	sub = (char *)malloc((i - (size_t)start + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = (size_t)start;
	while (s[i] && (i - (size_t)start) < len)
	{
		sub[i - (size_t)start] = s[i];
		i++;
	}
	sub[i - (size_t)start] = '\0';
	return (sub);
}
