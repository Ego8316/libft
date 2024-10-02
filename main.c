/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:17:58 by ego               #+#    #+#             */
/*   Updated: 2024/10/03 00:38:16 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *str)
{
	char	*cpy;
	size_t	i;

	cpy = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

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
	printf(">%zu\n", start);
	return (start);
}

static size_t	ft_strtrim_get_end(const char *s, const char *set, size_t start)
{
	size_t	s_len;
	size_t	end;

	s_len = ft_strlen(s);
	if (s_len == 0)
		return (0);
	end = s_len - 1;
	while (start < end && ft_char_in_str(s[end], set))
		end--;
	printf(">%zu\n", end);
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
	if (!set)
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

int	main(int argc, char **argv)
{
	(void)argc;
	char	*trim =  ft_strtrim(argv[1], argv[2]);
	printf(">>\"%s\"\n", trim);
	free(trim);
	return (0);
}
