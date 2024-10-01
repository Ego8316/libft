/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:09:41 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 16:55:30 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_isalnum(void)
{
	int	success;
	int	i;

	success = 0;
	i = -101;
	while (++i < 400)
	{
		if (isalnum(i) == ft_isalnum(i))
			success++;
		else
			printf("%sft_isalnum.c\t:\tTest %i failed: expected %i, got %i.%s\n", RED, i, isalnum(i), ft_isalnum(i), RESET);
	}
	if (success == 500)
	{
		printf("%sft_isalnum.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_isalnum.c\t:\tfailed (%i/500)%s\n", RED, success, RESET);
		return (0);
	}
}
