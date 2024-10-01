/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:24:01 by ego               #+#    #+#             */
/*   Updated: 2024/10/01 22:46:10 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_atoi(void)
{
	int		success = 0;
	char	test1[] = "154883";
	char	test2[] = "-14557";
	char	test3[] = "---14762";
	char	test4[] = "+11454";
	char	test5[] = "+47+5";
	char	test6[] = "\t\v\f\r\n \f-06050";
	char	test7[] = "47875...68";
	char	test8[] = "-        47875...68";

	// Test 1: Just a simple number
	if (atoi(test1) == ft_atoi(test1))
		success++;
	else
		printf("%sft_atoi.c\t:\tTest 1 failed: expected %i, got %i%s\n", RED, atoi(test1), ft_atoi(test1), RESET);

	// Test 2: One minus sign before the number
	if (atoi(test2) == ft_atoi(test2))
		success++;
	else
		printf("%sft_atoi.c\t:\tTest 2 failed: expected %i, got %i%s\n", RED, atoi(test2), ft_atoi(test2), RESET);

	// Test 3: Several minus signs before the number
	if (atoi(test3) == ft_atoi(test3))
		success++;
	else
		printf("%sft_atoi.c\t:\tTest 3 failed: expected %i, got %i%s\n", RED, atoi(test3), ft_atoi(test3), RESET);

	// Test 4: One plus sign before the number
	if (atoi(test4) == ft_atoi(test4))
		success++;
	else
		printf("%sft_atoi.c\t:\tTest 4 failed: expected %i, got %i%s\n", RED, atoi(test4), ft_atoi(test4), RESET);

	// Test 5: Two plus signs
	if (atoi(test5) == ft_atoi(test5))
		success++;
	else
		printf("%sft_atoi.c\t:\tTest 5 failed: expected %i, got %i%s\n", RED, atoi(test5), ft_atoi(test5), RESET);

	// Test 6: Several blank spaces before the number
	if (atoi(test6) == ft_atoi(test6))
		success++;
	else
		printf("%sft_atoi.c\t:\tTest 6 failed: expected %i, got %i%s\n", RED, atoi(test6), ft_atoi(test6), RESET);

	// Test 7: Number interrupted by non-digit characters
	if (atoi(test7) == ft_atoi(test7))
		success++;
	else
		printf("%sft_atoi.c\t:\tTest 7 failed: expected %i, got %i%s\n", RED, atoi(test7), ft_atoi(test7), RESET);

	// Test 8: Minus sign followed by spaces before the number
	if (atoi(test8) == ft_atoi(test8))
		success++;
	else
		printf("%sft_atoi.c\t:\tTest 8 failed: expected %i, got %i%s\n", RED, atoi(test8), ft_atoi(test8), RESET);

	if (success == 8)
	{
		printf("%sft_atoi.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_atoi.c\t:\tfailed (%i/8)%s\n", RED, success, RESET);
		return (0);
	}
}