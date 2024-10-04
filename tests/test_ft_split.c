/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:30:33 by ego               #+#    #+#             */
/*   Updated: 2024/10/04 14:25:23 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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
int	test_ft_split(void)
{
	int		success = 0;
	char	**split;

	// Test 1: Normal string with delimiter in the middle
	split = ft_split("hello world", ' ');
	if (split && strcmp(split[0], "hello") == 0 && strcmp(split[1], "world") == 0 && split[2] == NULL)
		success++;
	else
		printf("%sft_split.c\t:\tTest 1 failed: expected {\"hello\", \"world\", NULL}, got {\"%s\", \"%s\", %s}%s\n", RED, split[0], split[1], split[2], RESET);
	ft_split_free(split);

	// Test 2: Empty string
	split = ft_split("", ' ');
	if (split && split[0] == NULL)
		success++;
	else
		printf("%sft_split.c\t:\tTest 2 failed: expected {NULL}, got {\"%s\"}%s\n", RED, split[0], RESET);
	ft_split_free(split);

	// Test 3: String with only delimiters
	split = ft_split("     ", ' ');
	if (split && split[0] == NULL)
		success++;
	else
		printf("%sft_split.c\t:\tTest 3 failed: expected {NULL}, got {\"%s\"}%s\n", RED, split[0], RESET);
	ft_split_free(split);

	// Test 4: No delimiter in string
	split = ft_split("helloworld", ' ');
	if (split && strcmp(split[0], "helloworld") == 0 && split[1] == NULL)
		success++;
	else
		printf("%sft_split.c\t:\tTest 4 failed: expected {\"helloworld\", NULL}, got {\"%s\", %s}%s\n", RED, split[0], split[1], RESET);
	ft_split_free(split);

	// Test 5: String with multiple consecutive delimiters
	split = ft_split("hello   world", ' ');
	if (split && strcmp(split[0], "hello") == 0 && strcmp(split[1], "world") == 0 && split[2] == NULL)
		success++;
	else
		printf("%sft_split.c\t:\tTest 5 failed: expected {\"hello\", \"world\", NULL}, got {\"%s\", \"%s\", %s}%s\n", RED, split[0], split[1], split[2], RESET);
	ft_split_free(split);

	// Test 6: Delimiter at the start and end of the string
	split = ft_split(" hello world ", ' ');
	if (split && strcmp(split[0], "hello") == 0 && strcmp(split[1], "world") == 0 && split[2] == NULL)
		success++;
	else
		printf("%sft_split.c\t:\tTest 6 failed: expected {\"hello\", \"world\", NULL}, got {\"%s\", \"%s\", %s}%s\n", RED, split[0], split[1], split[2], RESET);
	ft_split_free(split);

	// Test 7: String with multiple delimiters and empty substrings
	split = ft_split("  hello   ", ' ');
	if (split && strcmp(split[0], "hello") == 0 && split[1] == NULL)
		success++;
	else
		printf("%sft_split.c\t:\tTest 7 failed: expected {\"hello\", NULL}, got {\"%s\", %s}%s\n", RED, split[0], split[1], RESET);
	ft_split_free(split);

	// Test 8: Null string
	split = ft_split(NULL, ' ');
	if (split == NULL)
		success++;
	else
	{
		printf("%sft_split.c\t:\tTest 8 failed: expected NULL, got %p%s\n", RED, split, RESET);
		ft_split_free(split);
	}
	
	// Test 9: Delimiter in the middle but no actual splitting
	split = ft_split("hello", 'x');
	if (split && strcmp(split[0], "hello") == 0 && split[1] == NULL)
		success++;
	else
		printf("%sft_split.c\t:\tTest 9 failed: expected {\"hello\", NULL}, got {\"%s\", %s}%s\n", RED, split[0], split[1], RESET);
	ft_split_free(split);

	// Test 10: Large string split
	split = ft_split("split,this,large,string", ',');
	if (split && strcmp(split[0], "split") == 0 && strcmp(split[1], "this") == 0 && strcmp(split[2], "large") == 0 && strcmp(split[3], "string") == 0 && split[4] == NULL)
		success++;
	else
		printf("%sft_split.c\t:\tTest 10 failed: expected {\"split\", \"this\", \"large\", \"string\", NULL}, got {\"%s\", \"%s\", \"%s\", \"%s\", %s}%s\n", RED, split[0], split[1], split[2], split[3], split[4], RESET);
	ft_split_free(split);

	// Test 11: Multiple delimiters at start and end of the string
	split = ft_split(",,hello,,world,,", ',');
	if (split && strcmp(split[0], "hello") == 0 && strcmp(split[1], "world") == 0 && split[2] == NULL)
		success++;
	else
		printf("%sft_split.c\t:\tTest 11 failed: expected {\"hello\", \"world\", NULL}, got {\"%s\", \"%s\", %s}%s\n", RED, split[0], split[1], split[2], RESET);
	ft_split_free(split);

	if (success == 11)
	{
		printf("%sft_split.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_split.c\t:\tfailed (%i/11)%s\n", RED, success, RESET);
		return (0);
	}
}
