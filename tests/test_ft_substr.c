/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:17:46 by ego               #+#    #+#             */
/*   Updated: 2024/10/02 16:44:24 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_substr(void)
{
	int		success = 0;
	char	*test1 = "hello world";
	char	*test2 = "";

	// Test 1: normal string, normal len, normal start
	char	*sub1 = ft_substr(test1, 6, 5);
	if (sub1 && strcmp("world", sub1) == 0)
		success++;
	else
		printf("%sft_substr.c\t:\tTest 1 failed: expected %s, got %s%s\n", RED, "world", sub1, RESET);
	free(sub1);

	// Test 2: normal string, len = 0, normal start
	char	*sub2 = ft_substr(test1, 6, 0);
	if (sub2 && strcmp("", sub2) == 0)
		success++;
	else
		printf("%sft_substr.c\t:\tTest 2 failed: expected %s, got %s%s\n", RED, "", sub2, RESET);
	free(sub2);

	// Test 3: normal string, len too big, normal start
	char	*sub3 = ft_substr(test1, 6, 15);
	if (sub3 && strcmp("world", sub3) == 0)
		success++;
	else
		printf("%sft_substr.c\t:\tTest 3 failed: expected %s, got %s%s\n", RED, "world", sub3, RESET);
	free(sub3);

	// Test 4: empty strig, normal len
	char	*sub4 = ft_substr(test2, 5, 15);
	if (sub4 && strcmp("", sub4) == 0)
		success++;
	else
		printf("%sft_substr.c\t:\tTest 4 failed: expected %s, got %s%s\n", RED, "", sub4, RESET);
	free(sub4);

	// Test 5: empty string, len = 0
	char	*sub5 = ft_substr(test2, 5, 15);
	if (sub5 && strcmp("", sub5) == 0)
		success++;
	else
		printf("%sft_substr.c\t:\tTest 5 failed: expected %s, got %s%s\n", RED, "", sub5, RESET);
	free(sub5);

	// Test 6: normal string, normal len, start out of range
	char	*sub6 = ft_substr(test1, 15, 5);
	if (sub6 && strcmp("", sub6) == 0)
		success++;
	else
		printf("%sft_substr.c\t:\tTest 6 failed: expected %s, got %s%s\n", RED, "", sub6, RESET);
	free(sub6);

	// Test 7: normal string, len = 0, start out of range
	char	*sub7 = ft_substr(test1, 15, 0);
	if (sub7 && strcmp("", sub7) == 0)
		success++;
	else
		printf("%sft_substr.c\t:\tTest 7 failed: expected %s, got %s%s\n", RED, "", sub7, RESET);
	free(sub7);

	// Test 8: normal string, len too big, start out of range
	char	*sub8 = ft_substr(test1, 15, 15);
	if (sub8 && strcmp("", sub8) == 0)
		success++;
	else
		printf("%sft_substr.c\t:\tTest 8 failed: expected %s, got %s%s\n", RED, "", sub8, RESET);
	free(sub8);
	
	// Test 9: NULL input
	char	*sub9 = ft_substr(NULL, 5, 5);
	if (!sub9)
		success++;
	else
		printf("%sft_substr.c\t:\tTest 9 failed: expected %p, got %p%s\n", RED, NULL, sub9, RESET);
	free(sub9);

	if (success == 9)
	{
		printf("%sft_substr.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_substr.c\t:\tfailed (%i/9)%s\n", RED, success, RESET);
		return (0);
	}
}
