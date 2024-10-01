/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:55:10 by ego               #+#    #+#             */
/*   Updated: 2024/10/01 21:56:34 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_strncmp(void)
{
	int		success = 0;
	char	test1[] = "abcdef";
	char	test2[] = "abcxyz";
	char	test3[] = "The quick brown fox";
	char	test4[] = "The quick brown dog";
	char	test5[] = "";
	char	test6[] = "The\0hidden part";
	char	test7[] = "The\200";

	// Test 1: Identical strings, full comparison
	if (strncmp(test1, test1, 6) == ft_strncmp(test1, test1, 6))
		success++;
	else
		printf("%sft_strncmp.c\t:\tTest 1 failed: expected %d, got %d%s\n", RED, strncmp(test1, test1, 6), ft_strncmp(test1, test1, 6), RESET);

	// Test 2: Different strings, non-zero return
	if (strncmp(test1, test2, 6) == ft_strncmp(test1, test2, 6))
		success++;
	else
		printf("%sft_strncmp.c\t:\tTest 2 failed: expected %d, got %d%s\n", RED, strncmp(test1, test2, 6), ft_strncmp(test1, test2, 6), RESET);

	// Test 3: Same prefix but difference after the nth character
	if (strncmp(test3, test4, 10) == ft_strncmp(test3, test4, 10))
		success++;
	else
		printf("%sft_strncmp.c\t:\tTest 3 failed: expected %d, got %d%s\n", RED, strncmp(test3, test4, 10), ft_strncmp(test3, test4, 10), RESET);

	// Test 4: Identical strings but compare less characters
	if (strncmp(test1, test2, 3) == ft_strncmp(test1, test2, 3))
		success++;
	else
		printf("%sft_strncmp.c\t:\tTest 4 failed: expected %d, got %d%s\n", RED, strncmp(test1, test2, 3), ft_strncmp(test1, test2, 3), RESET);

	// Test 5: Empty string comparison
	if (strncmp(test5, test5, 1) == ft_strncmp(test5, test5, 1))
		success++;
	else
		printf("%sft_strncmp.c\t:\tTest 5 failed: expected %d, got %d%s\n", RED, strncmp(test5, test5, 1), ft_strncmp(test5, test5, 1), RESET);

	// Test 6: Null character in the middle of one string
	if (strncmp(test6, "The hidden part", 16) == ft_strncmp(test6, "The hidden part", 16))
		success++;
	else
		printf("%sft_strncmp.c\t:\tTest 6 failed: expected %d, got %d%s\n", RED, strncmp(test6, "The hidden part", 16), ft_strncmp(test6, "The hidden part", 16), RESET);

	// Test 7: Compare up to '\0' (null terminator should stop comparison)
	if (strncmp(test6, "The hidden part", 20) == ft_strncmp(test6, "The hidden part", 20))
		success++;
	else
		printf("%sft_strncmp.c\t:\tTest 7 failed: expected %d, got %d%s\n", RED, strncmp(test6, "The hidden part", 20), ft_strncmp(test6, "The hidden part", 20), RESET);

	// Test 8: Comparison with non-ascii characters
	if (strncmp(test6, test7, 5) == ft_strncmp(test6, test7, 5))
		success++;
	else
		printf("%sft_strncmp.c\t:\tTest 7 failed: expected %d, got %d%s\n", RED, strncmp(test6, test7, 5), ft_strncmp(test6, test7, 5), RESET);

	if (success == 8)
	{
		printf("%sft_strncmp.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_strncmp.c\t:\tfailed (%d/8)%s\n", RED, success, RESET);
		return (0);
	}
}
