/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:02:38 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 16:55:24 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_isprint(void)
{
	int	success;
	int	i;

	success = 0;
	i = -101;
	while (++i < 400)
	{
		if (isprint(i) == ft_isprint(i))
			success++;
		else
			printf("%sft_isprint.c\t:\tTest %i failed: expected %i, got %i.%s\n", RED, i, isprint(i), ft_isprint(i), RESET);
	}
	if (success == 500)
	{
		printf("%sft_isprint.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_isprint.c\t:\tfailed (%i/500)%s\n", RED, success, RESET);
		return (0);
	}
}
