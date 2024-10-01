/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:11:42 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 16:55:28 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_isalpha(void)
{
	int	success;
	int	i;

	success = 0;
	i = -101;
	while (++i < 400)
	{
		if (isalpha(i) == ft_isalpha(i))
			success++;
		else
			printf("%sft_isalpha.c\t:\tTest %i failed: expected %i, got %i.%s\n", RED, i, isalpha(i), ft_isalpha(i), RESET);
	}
	if (success == 500)
	{
		printf("%sft_isalpha.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_isalpha.c\t:\tfailed (%i/500)%s\n", RED, success, RESET);
		return (0);
	}
}
