/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:27:14 by ego               #+#    #+#             */
/*   Updated: 2024/10/13 14:35:11 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_str(int c, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_strtrim_get_start(const char *s, const char *set)
{
	size_t	start;

	start = 0;
	while (ft_char_in_str(s[start], set))
		start++;
	return (start);
}

static size_t	ft_strtrim_get_end(const char *s, const char *set, size_t start)
{
	size_t	end;

	if (ft_strlen(s) == 0)
		return (0);
	end = ft_strlen(s) - 1;
	while (start < end && ft_char_in_str(s[end], set))
		end--;
	return (end);
}

char	*ft_strtrim(const char *s, const char *set)
{
	char	*trim;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	if (!set || !(*s) || !(*set))
		return (ft_strdup(s));
	start = ft_strtrim_get_start(s, set);
	end = ft_strtrim_get_end(s, set, start);
	trim = (char *)malloc((end - start + 2) * sizeof(char));
	if (!trim)
		return (NULL);
	i = 0;
	while (i < end - start + 1)
	{
		trim[i] = s[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
