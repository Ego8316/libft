/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:49:17 by ego               #+#    #+#             */
/*   Updated: 2024/10/01 21:57:10 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_memcmp(void)
{
	int		success = 0;
	char	test1[] = "abcdef";
	char	test2[] = "abcxyz";
	char	test3[] = "The quick brown fox";
	char	test4[] = "The quick brown dog";
	char	test5[] = "";
	char	test6[] = "The\0hidden part";
	char	test7[] = "The\0not so hidden";

	// Test 1: Identical strings
	if (memcmp(test1, test1, 6) == ft_memcmp(test1, test1, 6))
		success++;
	else
		printf("%sft_memcmp.c\t:\tTest 1 failed: expected %i, got %i%s\n", RED, memcmp(test1, test1, 6), ft_memcmp(test1, test1, 6), RESET);

	// Test 2: Different strings, non-zero return
	if (memcmp(test1, test2, 6) == ft_memcmp(test1, test2, 6))
		success++;
	else
		printf("%sft_memcmp.c\t:\tTest 2 failed: expected %i, got %i%s\n", RED, memcmp(test1, test2, 6), ft_memcmp(test1, test2, 6), RESET);

	// Test 3: Same prefix but difference after the 10th character
	if (memcmp(test3, test4, 19) == ft_memcmp(test3, test4, 19))
		success++;
	else
		printf("%sft_memcmp.c\t:\tTest 3 failed: expected %i, got %i%s\n", RED, memcmp(test3, test4, 19), ft_memcmp(test3, test4, 19), RESET);

	// Test 4: Comparing an empty string
	if (memcmp(test5, test5, 1) == ft_memcmp(test5, test5, 1))
		success++;
	else
		printf("%sft_memcmp.c\t:\tTest 4 failed: expected %i, got %i%s\n", RED, memcmp(test5, test5, 1), ft_memcmp(test5, test5, 1), RESET);

	// Test 5: Compare up to null terminator in hidden null case
	if (memcmp(test6, test6, 14) == ft_memcmp(test6, test6, 14))
		success++;
	else
		printf("%sft_memcmp.c\t:\tTest 5 failed: expected %i, got %i%s\n", RED, memcmp(test6, test6, 14), ft_memcmp(test6, test6, 14), RESET);

	// Test 6: Compare shorter length (no differences within the first few characters)
	if (memcmp(test1, test2, 3) == ft_memcmp(test1, test2, 3))
		success++;
	else
		printf("%sft_memcmp.c\t:\tTest 6 failed: expected %i, got %i%s\n", RED, memcmp(test1, test2, 3), ft_memcmp(test1, test2, 3), RESET);

	// Test 7: Comparison involving '\0'
	if (memcmp(test6, test6, 20) == ft_memcmp(test6, test6, 20))
		success++;
	else
		printf("%sft_memcmp.c\t:\tTest 7 failed: expected %i, got %i%s\n", RED, memcmp(test6, test6, 20), ft_memcmp(test6, test6, 20), RESET);

	// Test 8: Comparison after '\0'
	if (memcmp(test6, test7, 20) == ft_memcmp(test6, test7, 20))
		success++;
	else
		printf("%sft_memcmp.c\t:\tTest 7 failed: expected %i, got %i%s\n", RED, memcmp(test6, test7, 20), ft_memcmp(test6, test7, 20), RESET);

	if (success == 8)
	{
		printf("%sft_memcmp.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_memcmp.c\t:\tfailed (%i/8)%s\n", RED, success, RESET);
		return (0);
	}
}