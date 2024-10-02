/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:52:50 by ego               #+#    #+#             */
/*   Updated: 2024/10/03 00:21:01 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_strtrim(void)
{
	int success = 0;

	// Test 1: Empty string, empty set
	char *test1 = ft_strtrim("", "");
	if (strcmp(test1, "") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 1 failed: expected \"%s\", got \"%s\"%s\n", RED, "", test1, RESET);
	free(test1);

	// Test 2: Normal string, empty set
	char *test2 = ft_strtrim("hello", "");
	if (strcmp(test2, "hello") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 2 failed: expected \"%s\", got \"%s\"%s\n", RED, "hello", test2, RESET);
	free(test2);

	// Test 3: Empty string, not-empty set
	char *test3 = ft_strtrim("", "abc");
	if (strcmp(test3, "") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 3 failed: expected \"%s\", got \"%s\"%s\n", RED, "", test3, RESET);
	free(test3);

	// Test 4: Null string and null set
	char *test4 = ft_strtrim(NULL, NULL);
	if (!test4)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 4 failed: expected %s, got \"%s\"%s\n", RED, "NULL", test4, RESET);
	free(test4);

	// Test 5: Normal string, null set
	char *test5 = ft_strtrim("hello", NULL);
	if (strcmp(test5, "hello") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 5 failed: expected \"%s\", got \"%s\"%s\n", RED, "hello", test5, RESET);
	free(test5);

	// Test 6: Null string, not-empty set
	char *test6 = ft_strtrim(NULL, "abc");
	if (!test6)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 6 failed: expected %s, got \"%s\"%s\n", RED, "NULL", test6, RESET);
	free(test6);

	// Test 7: One-char set, one at the beginning
	char *test7 = ft_strtrim(" hello", " ");
	if (strcmp(test7, "hello") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 7 failed: expected \"%s\", got \"%s\"%s\n", RED, "hello", test7, RESET);
	free(test7);

	// Test 8: One-char set, one at the end
	char *test8 = ft_strtrim("hello ", " ");
	if (strcmp(test8, "hello") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 8 failed: expected \"%s\", got \"%s\"%s\n", RED, "hello", test8, RESET);
	free(test8);

	// Test 9: One-char set, one at the beginning and the end
	char *test9 = ft_strtrim(" hello ", " ");
	if (strcmp(test9, "hello") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 9 failed: expected \"%s\", got \"%s\"%s\n", RED, "hello", test9, RESET);
	free(test9);

	// Test 10: One-char set, several at the beginning and the end
	char *test10 = ft_strtrim("  hello  ", " ");
	if (strcmp(test10, "hello") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 10 failed: expected \"%s\", got \"%s\"%s\n", RED, "hello", test10, RESET);
	free(test10);

	// Test 11: Two-char set, several at the beginning and the end
	char *test11 = ft_strtrim("\t hello\t ", "\t ");
	if (strcmp(test11, "hello") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 11 failed: expected \"%s\", got \"%s\"%s\n", RED, "hello", test11, RESET);
	free(test11);

	// Test 12: Two-letters set, several at the beginning and the end
	char *test12 = ft_strtrim("aaabbbccc", "ac");
	if (strcmp(test12, "bbb") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 12 failed: expected \"%s\", got \"%s\"%s\n", RED, "bbb", test12, RESET);
	free(test12);

	// Test 13: Several characters in the set, and some in the middle
	char *test13 = ft_strtrim("\taahello worldcc \t", "ac \t");
	if (strcmp(test13, "hello world") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 13 failed: expected \"%s\", got \"%s\"%s\n", RED, "hello world", test13, RESET);
	free(test13);

	// Test 14: Whitespaces only
	char *test14 = ft_strtrim("   ", " ");
	if (strcmp(test14, "") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 14 failed: expected \"%s\", got \"%s\"%s\n", RED, "", test14, RESET);
	free(test14);

	// Test 15: One-char string that is in the set
	char *test15 = ft_strtrim("a", "a");
	if (strcmp(test15, "") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 15 failed: expected \"%s\", got \"%s\"%s\n", RED, "", test15, RESET);
	free(test15);

	// Test 16: Set contains all characters of the string
	char *test16 = ft_strtrim("abc", "abc");
	if (strcmp(test16, "") == 0)
		success++;
	else
		printf("%sft_strtrim.c\t:\tTest 16 failed: expected \"%s\", got \"%s\"%s\n", RED, "", test16, RESET);
	free(test16);

	if (success == 16)
	{
		printf("%sft_strtrim.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_strtrim.c\t:\tfailed (%i/16)%s\n", RED, success, RESET);
		return (0);
	}
}
