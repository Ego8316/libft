/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:55:35 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 16:55:26 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_isascii(void)
{
	int	success;
	int	i;

	success = 0;
	i = -101;
	while (++i < 400)
	{
		if (isascii(i) == ft_isascii(i))
			success++;
		else
			printf("%sft_isascii.c\t:\tTest %i failed: expected %i, got %i.%s\n", RED, i, isascii(i), ft_isascii(i), RESET);
	}
	if (success == 500)
	{
		printf("%sft_isascii.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_isascii.c\t:\tfailed (%i/500)%s\n", RED, success, RESET);
		return (0);
	}
}
