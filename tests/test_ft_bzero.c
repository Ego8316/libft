/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:40:49 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 14:42:38 by hcavet           ###   ########.fr       */
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

int	test_ft_bzero(void)
{
	int	success = 0;
	// Test 1: string
	char str1[] = "Hello world!";
	char str2[] = "Hello world!";

	bzero(str1, 5 * sizeof(char));
	ft_bzero(str2, 5 * sizeof(char));
	if (memcmp(str1, str2, 10 * sizeof(char)) == 0)
		success++;
	else
		printf("%sft_bzero.c: Test 1 failed: expected %s, got %s.%s\n", RED, str1, str2, RESET);


	// Test 2: integer array
	int	arr1[10];
	int	arr2[10];

	bzero(arr1, 10 * sizeof(int));
	ft_bzero(arr2, 10 * sizeof(int));
	if (memcmp(arr1, arr2, 10 * sizeof(int)) == 0)
		success++;
	else
	{
		printf("%sft_bzero.c: Test 2 failed: expected [ ", RED);
		print_array(arr1, 10);
		printf("], got [ ");
		print_array(arr2, 10);
		printf(" ]%s\n", RESET);
	}
	// Test 3: edge case len = 0
	bzero(arr1, (0));
	ft_bzero(arr2, 0);
	if (memcmp(arr1, arr2, 10 * sizeof(int)) == 0)
		success++;
	else
	{
		printf("%sft_bzero.c: Test 3 failed: expected [ ", RED);
		print_array(arr1, 10);
		printf("], got [ ");
		print_array(arr2, 10);
		printf(" ]%s\n", RESET);
	}

	if (success == 3)
	{
		printf("%sft_bzero.c: OK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_bzero.c: failed (%i/3)%s\n", RED, success, RESET);
		return (0);
	}
}
