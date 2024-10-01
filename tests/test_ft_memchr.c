/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:05:44 by ego               #+#    #+#             */
/*   Updated: 2024/10/01 21:56:57 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_memchr(void)
{
	int success = 0;
	char	test1[] = "salutsalut";
	char	test2[] = "Hello world!";
	char	test3[] = "The cake\0is a lie";
	char	test4[] = "Nothing to be found";

	// Test 1: Len = 0
	if (memchr(test1, 'a', 0) == ft_memchr(test1, 'a', 0))
		success++;
	else
		printf("%sft_memchr.c\t:\tTest 1 failed: expected %p, got %p%s\n", RED, memchr(test1, 'a', 0), ft_memchr(test1, 'a', 0), RESET);

	// Test 2: Basic sentence and a character to be found
	if (memchr(test2, 'w', 12) == ft_memchr(test2, 'w', 12))
		success++;
	else
		printf("%sft_memchr.c\t:\tTest 2 failed: expected %p, got %p%s\n", RED, memchr(test2, 'w', 12), ft_memchr(test2, 'w', 12), RESET);

	// Test 3: Null character in the middle
	if (memchr(test3, 'i', 17) == ft_memchr(test3, 'i', 17))
		success++;
	else
		printf("%sft_memchr.c\t:\tTest 3 failed: expected %p, got %p%s\n", RED, memchr(test3, 'a', 17), ft_memchr(test3, 'a', 17), RESET);

	// Test 4: Basic sentence and no character to be found
	if (memchr(test4, 'a', 19) == ft_memchr(test4, 'a', 19))
		success++;
	else
		printf("%sft_memchr.c\t:\tTest 4 failed: expected %p, got %p%s\n", RED, memchr(test4, 'a', 19), ft_memchr(test4, 'a', 19), RESET);

	// Test 5: Len too big
	if (memchr(test1, 'a', 15) == ft_memchr(test1, 'a', 15))
		success++;
	else
		printf("%sft_memchr.c\t:\tTest 1 failed: expected %p, got %p%s\n", RED, memchr(test1, 'a', 15), ft_memchr(test1, 'a', 15), RESET);

	if (success == 5)
	{
		printf("%sft_memchr.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_memchr.c\t:\tfailed (%i/5)%s\n", RED, success, RESET);
		return (0);
	}
}