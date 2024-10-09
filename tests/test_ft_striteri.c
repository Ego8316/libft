/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:01:53 by ego               #+#    #+#             */
/*   Updated: 2024/10/09 02:06:09 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_function(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int	test_ft_striteri(void)
{
	int		success = 0;
	char	str1[] = "hello";
	char	str2[] = "";
	char	str3[] = "x";
	char	str4[] = "HELLO";
	char	str5[] = "hello!@#";

	// Test 1: Apply uppercase transformation at even indices
	ft_striteri(str1, test_function);
	if (strcmp(str1, "HeLlO") == 0)
		success++;
	else
		printf("%sft_striteri.c\t:\tTest 1 failed: expected %s, got %s%s\n", RED, "HeLlO", str1, RESET);

	// Test 2: Empty string
	ft_striteri(str2, test_function);
	if (strcmp(str2, "") == 0)
		success++;
	else
		printf("%sft_striteri.c\t:\tTest 2 failed: expected %s, got %s%s\n", RED, "", str2, RESET);

	// Test 3: Single character string
	ft_striteri(str3, test_function);
	if (strcmp(str3, "X") == 0)
		success++;
	else
		printf("%sft_striteri.c\t:\tTest 3 failed: expected %s, got %s%s\n", RED, "X", str3, RESET);

	// Test 4: All-uppercase string (no changes expected)
	ft_striteri(str4, test_function);
	if (strcmp(str4, "HELLO") == 0)
		success++;
	else
		printf("%sft_striteri.c\t:\tTest 4 failed: expected %s, got %s%s\n", RED, "HELLO", str4, RESET);

	// Test 5: String with special characters
	ft_striteri(str5, test_function);
	if (strcmp(str5, "HeLlO!@#") == 0)
		success++;
	else
		printf("%sft_striteri.c\t:\tTest 5 failed: expected %s, got %s%s\n", RED, "HeLlO!@#", str5, RESET);

	// Test 6: NULL string
	ft_striteri(NULL, test_function);
	// Nothing to compare, if no crash, we assume success
	success++;

	if (success == 6)
	{
		printf("%sft_striteri.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_striteri.c\t:\tfailed (%i/6)%s\n", RED, success, RESET);
		return (0);
	}
}
