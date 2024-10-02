/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:07:26 by ego               #+#    #+#             */
/*   Updated: 2024/10/02 17:43:32 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_strjoin(void)
{
	int		success = 0;

	// Test 1: two normal strings
	char	*test1 = ft_strjoin("hello", " world");
	if (test1 && strcmp("hello world", test1) == 0)
		success++;
	else
		printf("%sft_strjoin.c\t:\tTest 1 failed: expected %s, got %s%s\n", RED, "hello world", test1, RESET);
	free(test1);

	// Test 2: one of the two is empty
	char	*test2 = ft_strjoin("", "hi there");
	if (test2 && strcmp("hi there", test2) == 0)
		success++;
	else
		printf("%sft_strjoin.c\t:\tTest 2 failed: expected %s, got %s%s\n", RED, "hi there", test2, RESET);
	free(test2);

	// Test 3: one of the two is NULL
	char	*test3 = ft_strjoin(NULL, "hi there");
	if (!test3)
		success++;
	else
		printf("%sft_strjoin.c\t:\tTest 3 failed: expected %p, got %p%s\n", RED, NULL, test3, RESET);
	free(test3);

	// Test 4: both strings are empty
	char *test4 = ft_strjoin("", "");
	if (test4 && strcmp("", test4) == 0)
		success++;
	else
		printf("%sft_strjoin.c\t:\tTest 4 failed: expected %s, got %s%s\n", RED, "", test4, RESET);
	free(test4);

	// Test 5: both strings are NULL
	char *test5 = ft_strjoin(NULL, NULL);
	if (!test5)
		success++;
	else
		printf("%sft_strjoin.c\t:\tTest 5 failed: expected %p, got %p%s\n", RED, NULL, test5, RESET);
	free(test5);

	// Test 6: first is NULL, second is empty
	char *test6 = ft_strjoin(NULL, "");
	if (!test6)
		success++;
	else
		printf("%sft_strjoin.c\t:\tTest 6 failed: expected %p, got %p%s\n", RED, NULL, test6, RESET);
	free(test6);

	// Test 7: first is empty, second is NULL
	char *test7 = ft_strjoin("", NULL);
	if (!test7)
		success++;
	else
		printf("%sft_strjoin.c\t:\tTest 7 failed: expected %p, got %p%s\n", RED, NULL, test7, RESET);
	free(test7);

	if (success == 7)
	{
		printf("%sft_strjoin.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_strjoin.c\t:\tfailed (%i/7)%s\n", RED, success, RESET);
		return (0);
	}
}
