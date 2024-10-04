/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:47:27 by ego               #+#    #+#             */
/*   Updated: 2024/10/04 14:54:17 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_strnstr(void)
{
	int		success = 0;
	char	haystack1[] = "There is a needle in the haystack";
	char	haystack2[] = "There is not here";
	char	haystack3[] = "";
	char	needle1[] = "needle";
	char	needle2[] = "";

	// Test 1: needle is in haystack, len big enough
	if (strnstr(haystack1, needle1, 33) == ft_strnstr(haystack1, needle1, 33))
		success++;
	else
		printf("%sft_strnstr.c\t:\tTest 1 failed: expected %s, got %s%s\n", RED, strnstr(haystack1, needle1, 33), ft_strnstr(haystack1, needle1, 33), RESET);
	
	// Test 2: needle is in haystack, len not big enough
	if (strnstr(haystack1, needle1, 25) == ft_strnstr(haystack1, needle1, 25))
		success++;
	else
		printf("%sft_strnstr.c\t:\tTest 2 failed: expected %s, got %s%s\n", RED, strnstr(haystack1, needle1, 25), ft_strnstr(haystack1, needle1, 25), RESET);
	
	// Test 3: needle is not in haystack
	if (strnstr(haystack2, needle1, 33) == ft_strnstr(haystack2, needle1, 33))
		success++;
	else
		printf("%sft_strnstr.c\t:\tTest 3 failed: expected %s, got %s%s\n", RED, strnstr(haystack2, needle1, 33), ft_strnstr(haystack2, needle1, 33), RESET);
	
	// Test 4: needle is an empty string, haystack is not
	if (strnstr(haystack1, needle2, 35) == ft_strnstr(haystack1, needle2, 35))
		success++;
	else
		printf("%sft_strnstr.c\t:\tTest 4 failed: expected %s, got %s%s\n", RED, strnstr(haystack1, needle2, 35), ft_strnstr(haystack1, needle2, 35), RESET);

	// Test 5: haystack is an empty string, needle is not
	if (strnstr(haystack3, needle1, 35) == ft_strnstr(haystack3, needle1, 35))
		success++;
	else
		printf("%sft_strnstr.c\t:\tTest 5 failed: expected %s, got %s%s\n", RED, strnstr(haystack3, needle1, 35), ft_strnstr(haystack3, needle1, 35), RESET);

	// Test 6: both are empty strings
	if (strnstr(haystack3, needle2, 35) == ft_strnstr(haystack3, needle2, 35))
		success++;
	else
		printf("%sft_strnstr.c\t:\tTest 6 failed: expected %s, got %s%s\n", RED, strnstr(haystack3, needle2, 35), ft_strnstr(haystack2, needle1, 35), RESET);

	
	if (success == 6)
	{
		printf("%sft_strnstr.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_strnstr.c\t:\tfailed (%i/6)%s\n", RED, success, RESET);
		return (0);
	}
}