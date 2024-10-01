/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:47:27 by ego               #+#    #+#             */
/*   Updated: 2024/10/01 22:05:45 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_strnstr(void)
{
	int		success = 0;
	char	big1[] = "There is a needle in the haystack";
	char	big2[] = "There is not here";
	char	big3[] = "";
	char	little1[] = "needle";
	char	little2[] = "";

	// Test 1: little is in big, len big enough
	if (strnstr(big1, little1, 33) == ft_strnstr(big1, little1, 33))
		success++;
	else
		printf("%sft_strnstr.c\t:\tTest 1 failed: expected %s, got %s%s\n", RED, strnstr(big1, little1, 33), ft_strnstr(big1, little1, 33), RESET);
	
	// Test 2: little is in big, len not big enough
	if (strnstr(big1, little1, 25) == ft_strnstr(big1, little1, 25))
		success++;
	else
		printf("%sft_strnstr.c\t:\tTest 2 failed: expected %s, got %s%s\n", RED, strnstr(big1, little1, 25), ft_strnstr(big1, little1, 25), RESET);
	
	// Test 3: little is not in big
	if (strnstr(big2, little1, 33) == ft_strnstr(big2, little1, 33))
		success++;
	else
		printf("%sft_strnstr.c\t:\tTest 3 failed: expected %s, got %s%s\n", RED, strnstr(big2, little1, 33), ft_strnstr(big2, little1, 33), RESET);
	
	// Test 4: little is an empty string, big is not
	if (strnstr(big1, little2, 35) == ft_strnstr(big1, little2, 35))
		success++;
	else
		printf("%sft_strnstr.c\t:\tTest 4 failed: expected %s, got %s%s\n", RED, strnstr(big1, little2, 35), ft_strnstr(big1, little2, 35), RESET);

	// Test 5: big is an empty string, little is not
	if (strnstr(big3, little1, 35) == ft_strnstr(big3, little1, 35))
		success++;
	else
		printf("%sft_strnstr.c\t:\tTest 5 failed: expected %s, got %s%s\n", RED, strnstr(big3, little1, 35), ft_strnstr(big3, little1, 35), RESET);

	// Test 6: both are empty strings
	if (strnstr(big3, little2, 35) == ft_strnstr(big3, little2, 35))
		success++;
	else
		printf("%sft_strnstr.c\t:\tTest 6 failed: expected %s, got %s%s\n", RED, strnstr(big3, little2, 35), ft_strnstr(big2, little1, 35), RESET);

	
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