/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:14:57 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 20:53:46 by ego              ###   ########.fr       */
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

int	test_ft_memcpy(void)
{
	int		success = 0;
	char	src1[] = "hello";
	int		src2[10];
	char	dest1[] = "world!!!";
	char	dest2[] = "world!!!";
	int		dest3[10];
	int		dest4[10];

	memset(src2, 5, 10 * sizeof(int));
	memset(dest3, 2, 10 * sizeof(int));
	memset(dest4, 2, 10 * sizeof(int));

	memcpy(dest1, src1, 5 * sizeof(char));
	ft_memcpy(dest2, src1, 5 * sizeof(char));
	if (memcmp(dest1, dest2, 5 * sizeof(char)) == 0)
		success++;
	else
		printf("%sft_memcpy.c\t:\tTest 1 failed: expected %s, got %s.%s\n", RED, dest1, dest2, RESET);

	memcpy(dest3, src2, 10 * sizeof(int));
	ft_memcpy(dest4, src2, 10 * sizeof(int));
	if (memcmp(dest3, dest4, 10 * sizeof(int)) == 0)
		success++;
	else
	{
		printf("%sft_memcpy.c\t:\tTest 2 failed: expected [ ", RED);
		print_array(dest3, 10);
		printf("], got [ ");
		print_array(dest4, 10);
		printf(" ]%s\n", RESET);
	}
	if (success == 2)
	{
		printf("%sft_memcpy.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_memcpy.c\t:\tfailed (%i/2)%s\n", RED, success, RESET);
		return (0);
	}
}