/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:28:30 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 17:29:21 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_tolower(void)
{
	int	success;
	int	i;

	success = 0;
	i = -101;
	while (++i < 400)
	{
		if (tolower(i) == ft_tolower(i))
			success++;
		else
			printf("%sft_tolower.c\t:\tTest %i failed: expected %i, got %i.%s\n", RED, i, tolower(i), ft_tolower(i), RESET);
	}
	if (success == 500)
	{
		printf("%sft_tolower.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_tolower.c\t:\tfailed (%i/500)%s\n", RED, success, RESET);
		return (0);
	}
}
