/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:50:33 by ego               #+#    #+#             */
/*   Updated: 2024/10/02 17:05:09 by ego              ###   ########.fr       */
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

int	test_ft_calloc(void)
{
	int		success = 0;
	int		*arr1, *arr2;
	char	*str1, *str2;
	size_t	nmemb = 5, size = sizeof(int);

	// Test 1: allocate memory for five integers
	arr1 = (int *)calloc(nmemb, size);
	arr2 = (int *)ft_calloc(nmemb, size);
	if (arr1 && arr2 && memcmp(arr1, arr2, nmemb * size) == 0)
		success++;
	else
	{
		printf("%sft_calloc.c\t:\tTest 1 failed: expected [ ", RED);
		print_array(arr1, nmemb);
		printf("], got [ ");
		print_array(arr2, nmemb);
		printf(" ]%s\n", RESET);
	}
	free(arr1);
	free(arr2);

	// Test 2: allocate memory for a string of five characters
	size = sizeof(char);
	str1 = (char *)calloc(nmemb, size);
	str2 = (char *)ft_calloc(nmemb, size);
	if (str1 && str2 && memcmp(str1, str2, nmemb * size) == 0)
		success++;
	else
		printf("%sft_calloc.c\t:\tTest 2 failed: expected %s, got %s%s\n", RED, str1, str2, RESET);
	free(str1);
	free(str2);

	// Test 3: allocate memory for zero elements
	size = sizeof(char);
	str1 = (char *)calloc(0, size);
	str2 = (char *)ft_calloc(0, size);
	if ((str1 && str2) || (!str1 && !str2))
		success++;
	else
		printf("%sft_calloc.c\t:\tTest 3 failed: expected %p, got %p%s\n", RED, str1, str2, RESET);
	free(str1);
	free(str2);

	if (success == 3)
	{
		printf("%sft_calloc.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_calloc.c\t:\tfailed (%i/3)%s\n", RED, success, RESET);
		return (0);
	}
}
