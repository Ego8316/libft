/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:46:21 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 16:56:19 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	print_array(int *arr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		printf("%i ", arr[i]);
	return ;
}

int	test_ft_memset(void)
{
	int	success = 0;
	// Test 1: string
	char str1[] = "Hello world!";
	char str2[] = "Hello world!";

	memset(str1, '.', 5 * sizeof(char));
	ft_memset(str2, '.', 5 * sizeof(char));
	if (memcmp(str1, str2, 10 * sizeof(char)) == 0)
		success++;
	else
		printf("%sft_memset.c\t:\tTest 1 failed: expected %s, got %s.%s\n", RED, str1, str2, RESET);


	// Test 2: integer array
	int	arr1[10];
	int	arr2[10];

	memset(arr1, 3, 10 * sizeof(int));
	ft_memset(arr2, 3, 10 * sizeof(int));
	if (memcmp(arr1, arr2, 10 * sizeof(int)) == 0)
		success++;
	else
	{
		printf("%sft_memset.c\t:\tTest 2 failed: expected [ ", RED);
		print_array(arr1, 10);
		printf("], got [ ");
		print_array(arr2, 10);
		printf(" ]%s\n", RESET);
	}
	// Test 3: edge case len = 0
	memset(arr1, 8, (0));
	ft_memset(arr2, 8, 0);
	if (memcmp(arr1, arr2, 10 * sizeof(int)) == 0)
		success++;
	else
	{
		printf("%sft_memset.c\t:\tTest 3 failed: expected [ ", RED);
		print_array(arr1, 10);
		printf("], got [ ");
		print_array(arr2, 10);
		printf(" ]%s\n", RESET);
	}

	if (success == 3)
	{
		printf("%sft_memset.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_memset.c\t:\tfailed (%i/3)%s\n", RED, success, RESET);
		return (0);
	}
}
