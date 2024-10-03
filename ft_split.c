/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:29:31 by ego               #+#    #+#             */
/*   Updated: 2024/10/04 01:48:32 by ego              ###   ########.fr       */
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
		if (s[i] == 0 && is_word == 1)
			is_word = 0;
		i++;
	}
	return (nb_words);
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

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	i;
	size_t	word_len;

	split = (char **)malloc((ft_split_count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		word_len = 0;
		while (*s && *s != c)
		{
			word_len++;
			s++;
		}
		if (i < ft_split_count_words(s, c))
		{
			split[i] = ft_substr(s - word_len, 0, word_len);
			if (!(split[i]))
				return (ft_split_free(split));
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}
