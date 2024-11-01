/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:29:31 by ego               #+#    #+#             */
/*   Updated: 2024/10/13 14:34:49 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_count_words(const char *s, char c)
{
	size_t	i;
	size_t	nb_words;
	int		is_word;

	i = 0;
	nb_words = 0;
	is_word = 0;
	while (s[i])
	{
		if (s[i] != c && is_word == 0)
		{
			is_word = 1;
			nb_words++;
		}
		if (s[i] == c && is_word == 1)
			is_word = 0;
		i++;
	}
	return (nb_words);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*ndup;
	size_t	i;

	if (!n)
		return (NULL);
	ndup = (char *)malloc((n + 1) * sizeof(char));
	if (!ndup)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		ndup[i] = s[i];
		i++;
	}
	ndup[i] = '\0';
	return (ndup);
}

static char	**ft_split_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static size_t	ft_split_get_word_len(const char *s, char c)
{
	size_t	word_len;

	word_len = 0;
	while (*s && *s != c)
	{
		word_len++;
		s++;
	}
	return (word_len);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	i;
	size_t	word_len;

	if (!s)
		return (NULL);
	split = (char **)malloc((ft_split_count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			word_len = ft_split_get_word_len(s, c);
			split[i] = ft_strndup(s, word_len);
			if (!(split[i++]))
				return (ft_split_free(split));
			s += word_len;
		}
	}
	split[i] = NULL;
	return (split);
}