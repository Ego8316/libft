/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:35:56 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 16:55:58 by hcavet           ###   ########.fr       */
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

int	test_ft_memmove(void)
{
	int		success = 0;
	char	src1[] = "hello";
	int		src2[10];
	char	dest1[] = "world!!!";
	char	dest2[] = "world!!!";
	int		dest3[10];
	int		dest4[10];
	char	overlap_dest1[] = "abcdefghijk";
	char	overlap_dest2[] = "abcdefghijk";

	// Fill src2 with value 5 and dest arrays with value 2
	memset(src2, 5, 10 * sizeof(int));
	memset(dest3, 2, 10 * sizeof(int));
	memset(dest4, 2, 10 * sizeof(int));

	// Test 1: Simple non-overlapping strings
	memmove(dest1, src1, 5 * sizeof(char));
	ft_memmove(dest2, src1, 5 * sizeof(char));
	if (memcmp(dest1, dest2, 5 * sizeof(char)) == 0)
		success++;
	else
		printf("%sft_memmove.c\t:\tTest 1 failed: expected %s, got %s.%s\n", RED, dest1, dest2, RESET);

	// Test 2: Simple non-overlapping integer arrays
	memmove(dest3, src2, 10 * sizeof(int));
	ft_memmove(dest4, src2, 10 * sizeof(int));
	if (memcmp(dest3, dest4, 10 * sizeof(int)) == 0)
		success++;
	else
	{
		printf("%sft_memmove.c\t:\tTest 2 failed: expected [ ", RED);
		print_array(dest3, 10);
		printf("], got [ ");
		print_array(dest4, 10);
		printf(" ]%s\n", RESET);
	}

	// Test 3: Overlapping regions (src < dest)
	memmove(overlap_dest1 + 2, overlap_dest1, 5 * sizeof(char));
	ft_memmove(overlap_dest2 + 2, overlap_dest2, 5 * sizeof(char));
	if (memcmp(overlap_dest1, overlap_dest2, 10 * sizeof(char)) == 0)
		success++;
	else
		printf("%sft_memmove.c\t:\tTest 3 failed: expected %s, got %s.%s\n", RED, overlap_dest1, overlap_dest2, RESET);

	// Test 4: Overlapping regions (dest < src)
	memmove(overlap_dest1, overlap_dest1 + 2, 5 * sizeof(char));
	ft_memmove(overlap_dest2, overlap_dest2 + 2, 5 * sizeof(char));
	if (memcmp(overlap_dest1, overlap_dest2, 10 * sizeof(char)) == 0)
		success++;
	else
		printf("%sft_memmove.c\t:\tTest 4 failed: expected %s, got %s.%s\n", RED, overlap_dest1, overlap_dest2, RESET);

	// Success output
	if (success == 4)
	{
		printf("%sft_memmove.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_memmove.c\t:\tfailed (%i/4)%s\n", RED, success, RESET);
		return (0);
	}
}
