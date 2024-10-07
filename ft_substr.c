/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:18:45 by ego               #+#    #+#             */
/*   Updated: 2024/10/07 21:05:46 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_substrlen(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (0);
	if (s_len - start < len)
		return (s_len - start);
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	sub_len;

	if (!s)
		return (NULL);
	sub_len = ft_substrlen(s, start, len);
	sub = (char *)malloc((sub_len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = -1;
	while (++i < sub_len)
		sub[i] = s[i + start];
	sub[i] = '\0';
	return (sub);
}
