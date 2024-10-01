/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:15:37 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 14:42:07 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_strlen(void)
{
	const char	*tests[3] = {"Hello world!", "", "\x01\x02\x03"};
	int			success;
	int			i;

	i = -1;
	success = 0;
	while (++i < 3)
	{
		if (strlen(tests[i]) == ft_strlen(tests[i]))
			success++;
		else
			printf("%sft_strlen.c: Test %i failed: expected %lu, got %zu.%s\n", RED, i + 1, strlen(tests[i]), ft_strlen(tests[i]), RESET);
	}
	if (success == 3)
	{
		printf("%sft_strlen.c: OK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_strlen.c: failed (%i/3)%s\n", RED, success, RESET);
		return (0);
	}
}
