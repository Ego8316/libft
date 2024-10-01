/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:07:26 by ego               #+#    #+#             */
/*   Updated: 2024/10/02 00:16:18 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_strdup(void)
{
	int		success = 0;
	char	*test1 = "hello";
	char	*test2 = "";
	char	*test3 = "hello\0world";

	// Test 1: Normal string
	char	*dup1 = ft_strdup(test1);
	if (dup1 && strcmp(dup1, test1) == 0)
		success++;
	else
		printf("%sft_strdup.c\t:\tTest 1 failed: expected %s, got %s%s\n", RED, test1, dup1, RESET);
	free(dup1);

	// Test 2: Empty string
	char	*dup2 = ft_strdup(test2);
	if (dup2 && strcmp(dup2, test2) == 0)
		success++;
	else
		printf("%sft_strdup.c\t:\tTest 2 failed: expected %s, got %s%s\n", RED, test2, dup2, RESET);
	free(dup2);
	
	// Test 3: String with NULL character in the middle
	char	*dup3 = ft_strdup(test3);
	if (dup3 && strcmp(dup3, test3) == 0)
		success++;
	else
		printf("%sft_strdup.c\t:\tTest 3 failed: expected %s, got %s%s\n", RED, test3, dup3, RESET);
	free(dup3);

	// Test 4: Multiple duplicates
	char	*dup4 = ft_strdup(test1);
	char	*dup5 = ft_strdup(test1);
	if (dup4 != dup5)
		success++;
	else
		printf("%sft_strdup.c\t:\tTest 4 failed: two identical duplicates%s\n", RED, RESET);
	free(dup4);
	free(dup5);

	if (success == 4)
	{
		printf("%sft_strdup.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_strdup.c\t:\tfailed (%i/4)%s\n", RED, success, RESET);
		return (0);
	}
}
