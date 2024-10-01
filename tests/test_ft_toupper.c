/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:27:44 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 17:28:18 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_toupper(void)
{
	int	success;
	int	i;

	success = 0;
	i = -101;
	while (++i < 400)
	{
		if (toupper(i) == ft_toupper(i))
			success++;
		else
			printf("%sft_toupper.c\t:\tTest %i failed: expected %i, got %i.%s\n", RED, i, toupper(i), ft_toupper(i), RESET);
	}
	if (success == 500)
	{
		printf("%sft_toupper.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_toupper.c\t:\tfailed (%i/500)%s\n", RED, success, RESET);
		return (0);
	}
}
