/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:39:52 by ego               #+#    #+#             */
/*   Updated: 2024/10/01 21:56:17 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_strrchr(void)
{
	int		success = 0;
	char	test1[] = "";
	char	test2[] = "Hello world!";
	char	test3[] = "The cake\0is a lie";
	char	test4[] = "Nothing to be found";

	// Test 1: Empty string
	if (ft_strrchr(test1, 'a') == strrchr(test1, 'a'))
		success++;
	else
		printf("%sft_strrchr.c\t:\tTest 1 failed: expected %s, got %s%s\n", RED, strrchr(test1, 'a'), ft_strrchr(test1, 'a'), RESET);

	// Test 2: Basic sentence and a character to be found
	if (strrchr(test2, 'w') == ft_strrchr(test2, 'w'))
		success++;
	else
		printf("%sft_strrchr.c\t:\tTest 2 failed: expected %s, got %s%s\n", RED, strrchr(test2, 'w'), ft_strrchr(test2, 'w'), RESET);

	// Test 3: Null character in the middle
	if (ft_strrchr(test3, 'i') == strrchr(test3, 'i'))
		success++;
	else
		printf("%sft_strrchr.c\t:\tTest 3 failed: expected %s, got %s%s\n", RED, strrchr(test3, 'i'), ft_strrchr(test3, 'i'), RESET);

	// Test 4: Basic sentence and no character to be found
	if (ft_strrchr(test4, 'a') == strrchr(test4, 'a'))
		success++;
	else
		printf("%sft_strrchr.c\t:\tTest 4 failed: expected %s, got %s%s\n", RED, strrchr(test4, 'a'), ft_strrchr(test4, 'a'), RESET);

	if (success == 4)
	{
		printf("%sft_strrchr.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_strrchr.c\t:\tfailed (%i/4)%s\n", RED, success, RESET);
		return (0);
	}
}
