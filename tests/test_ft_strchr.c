/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:29:45 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 21:57:50 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_strchr(void)
{
	int success = 0;
	char	test1[1] = "";
	char	test2[12] = "Hello world!";
	char	test3[17] = "The cake\0is a lie";
	char	test4[19] = "Nothing to be found";

	// Test 1: Empty string
	if (strchr(test1, 'a') == ft_strchr(test1, 'a'))
		success++;
	else
		printf("%sft_strchr.c\t:\tTest 1 failed: expected %s, got %s%s\n", RED, strchr(test1, 'a'), ft_strchr(test1, 'a'), RESET);

	// Test 2: Basic sentence and a character to be found
	if (strcmp(strchr(test2, 'w'), ft_strchr(test2, 'w')) == 0)
		success++;
	else
		printf("%sft_strchr.c\t:\tTest 2 failed: expected %s, got %s%s\n", RED, strchr(test2, 'w'), ft_strchr(test2, 'w'), RESET);

	// Test 3: Null character in the middle
	if (strchr(test3, 'i') == ft_strchr(test3, 'i'))
		success++;
	else
		printf("%sft_strchr.c\t:\tTest 3 failed: expected %s, got %s%s\n", RED, strchr(test3, 'i'), ft_strchr(test3, 'i'), RESET);

	// Test 4: Basic sentence and no character to be found
	if (strchr(test4, 'a') == ft_strchr(test4, 'a'))
		success++;
	else
		printf("%sft_strchr.c\t:\tTest 4 failed: expected %s, got %s%s\n", RED, strchr(test4, 'a'), ft_strchr(test4, 'a'), RESET);
	
	if (success == 4)
	{
		printf("%sft_strchr.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_strchr.c\t:\tfailed (%i/4)%s\n", RED, success, RESET);
		return (0);
	}
}
