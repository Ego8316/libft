/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:28:11 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/04 16:11:01 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_itoa(void)
{
	int		success = 0;
	char	*itoa;

	// Test 1: Minimum int value (-2147483648)
	itoa = ft_itoa(-2147483648);
	if (itoa && strcmp(itoa, "-2147483648") == 0)
		success++;
	else
		printf("%sft_itoa.c\t:\tTest 1 failed: expected %s, got %s%s\n", RED, "-2147483648", itoa, RESET);
	free(itoa);

	// Test 2: Maximum int value (2147483647)
	itoa = ft_itoa(2147483647);
	if (itoa && strcmp(itoa, "2147483647") == 0)
		success++;
	else
		printf("%sft_itoa.c\t:\tTest 2 failed: expected %s, got %s%s\n", RED, "2147483647", itoa, RESET);
	free(itoa);

	// Test 3: Positive number (1505)
	itoa = ft_itoa(1505);
	if (itoa && strcmp(itoa, "1505") == 0)
		success++;
	else
		printf("%sft_itoa.c\t:\tTest 3 failed: expected %s, got %s%s\n", RED, "1505", itoa, RESET);
	free(itoa);

	// Test 4: Positive number (42)
	itoa = ft_itoa(42);
	if (itoa && strcmp(itoa, "42") == 0)
		success++;
	else
		printf("%sft_itoa.c\t:\tTest 4 failed: expected %s, got %s%s\n", RED, "42", itoa, RESET);
	free(itoa);

	// Test 5: Negative number (-5987)
	itoa = ft_itoa(-5987);
	if (itoa && strcmp(itoa, "-5987") == 0)
		success++;
	else
		printf("%sft_itoa.c\t:\tTest 5 failed: expected %s, got %s%s\n", RED, "-5987", itoa, RESET);
	free(itoa);

	// Test 6: Negative number (-5050)
	itoa = ft_itoa(-5050);
	if (itoa && strcmp(itoa, "-5050") == 0)
		success++;
	else
		printf("%sft_itoa.c\t:\tTest 6 failed: expected %s, got %s%s\n", RED, "-5050", itoa, RESET);
	free(itoa);

	// Test 7: Zero (0)
	itoa = ft_itoa(0);
	if (itoa && strcmp(itoa, "0") == 0)
		success++;
	else
		printf("%sft_itoa.c\t:\tTest 7 failed: expected %s, got %s%s\n", RED, "0", itoa, RESET);
	free(itoa);

	if (success == 7)
	{
		printf("%sft_itoa.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_itoa.c\t:\tfailed (%i/7)%s\n", RED, success, RESET);
		return (0);
	}
}
