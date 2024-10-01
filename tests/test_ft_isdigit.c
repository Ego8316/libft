/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:02:10 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 14:24:51 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_isdigit(void)
{
	int	success;
	int	i;

	success = 0;
	i = -101;
	while (++i < 400)
	{
		if (isdigit(i) == ft_isdigit(i))
			success++;
		else
			printf("%sft_isdigit.c: Test %i failed: expected %i, got %i.%s\n", RED, i, isdigit(i), ft_isdigit(i), RESET);
	}
	if (success == 500)
	{
		printf("%sft_isdigit.c: OK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_isdigit.c: failed (%i/500)%s\n", RED, success, RESET);
		return (0);
	}
}
