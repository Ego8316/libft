/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:14:03 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/09 02:04:48 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static char	test_function(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	test_ft_strmapi(void)
{
	int		success = 0;
	char	*result;

	// Test 1: Apply uppercase transformation at even indices
	result = ft_strmapi("hello", test_function);
	if (result && strcmp(result, "HeLlO") == 0)
		success++;
	else
		printf("%sft_strmapi.c\t:\tTest 1 failed: expected %s, got %s%s\n", RED, "HeLlO", result, RESET);
	free(result);

	// Test 2: Empty string
	result = ft_strmapi("", test_function);
	if (result && strcmp(result, "") == 0)
		success++;
	else
		printf("%sft_strmapi.c\t:\tTest 2 failed: expected %s, got %s%s\n", RED, "", result, RESET);
	free(result);

	// Test 3: String of one character
	result = ft_strmapi("x", test_function);
	if (result && strcmp(result, "X") == 0)
		success++;
	else
		printf("%sft_strmapi.c\t:\tTest 3 failed: expected %s, got %s%s\n", RED, "X", result, RESET);
	free(result);

	// Test 4: String of uppercase characters (no change expected)
	result = ft_strmapi("HELLO", test_function);
	if (result && strcmp(result, "HELLO") == 0)
		success++;
	else
		printf("%sft_strmapi.c\t:\tTest 4 failed: expected %s, got %s%s\n", RED, "HELLO", result, RESET);
	free(result);

	// Test 5: NULL string
	result = ft_strmapi(NULL, test_function);
	if (!result)
		success++;
	else
		printf("%sft_strmapi.c\t:\tTest 5 failed: expected %s, got %s%s\n", RED, "NULL", result, RESET);

	// Test 6: String with special characters
	result = ft_strmapi("hello!@#", test_function);
	if (result && strcmp(result, "HeLlO!@#") == 0)
		success++;
	else
		printf("%sft_strmapi.c\t:\tTest 6 failed: expected %s, got %s%s\n", RED, "HeLlO!@#", result, RESET);
	free(result);

	if (success == 6)
	{
		printf("%sft_strmapi.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_strmapi.c\t:\tfailed (%i/6)%s\n", RED, success, RESET);
		return (0);
	}
}
